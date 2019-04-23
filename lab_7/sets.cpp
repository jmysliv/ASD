#include <iostream>
using namespace std;
const int N=6;
/*
 * Dana jest tablica bool A[N][N]; Gracz początkowo znajduje się na (zadanej) pozycji(x, y),
dla której zachodzi A[y][x] == true. Z danej pozycji wolno bezpośrednio przejść jedynie na pozycję,
której dokładnie jedna współrzędna różni się o 1, oraz której wartość w tablicy A wynosi true.
Proszę napisać funkcję obliczający do ilu różnych pozycji może dojść gracz startując z zadanej pozycji(x, y).
 */

struct node;

struct set{
    node *first;
    node *last;
    int len;
};
struct node{
    node *next;
    set * start;
};

set* make_set(node *n){
    set *s = new set;
    s->first = n;
    s->last = n;
    s->len = 1;
    n->start=s;
    n->next=NULL;
    return s;
}

set * findset(node *n){
    return n->start;
}

set* unite(set * s1, set* s2){
    if(s1==s2) return s1;
    if(s1->len>s2->len){
        s1->len+=s2->len;
        s1->last->next = s2 ->first;
        s1->last = s2->last;
        node *p = s2->first;
        while(p!=NULL){
            p->start=s1;
            p=p->next;
        }
        delete(s2);
        return s1;
    }
    s2->len+=s1->len;
    s2->last->next = s1 ->first;
    s2->last = s1->last;
    node *p = s1->first;
    while(p!=NULL){
        p->start=s2;
        p=p->next;
    }
    delete(s1);
    return s2;
}

void add(node *p, node *n){
    p->next = n;
    n->next = NULL;
    n->start = p->start;
    findset(n)->len++;
    findset(n)->last=n;
}

int how_many(bool A[N][N], int x, int y){
    node *tab[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!A[i][j]) continue;
            node *n = new node;
            tab[i][j]=n;
            if(i-1>=0 && A[i-1][j]){
                add(tab[i-1][j], n);
                if(j-1>=0 && A[i][j-1]){
                    unite(findset(tab[i][j-1]), findset(n));
                }
            }
            else if(j-1>=0 && A[i][j-1]) add(tab[i][j-1], n);
            else make_set(n);
        }
    }

    return findset(tab[x][y])->len;

}




int main() {

    bool A[N][N]={false, true, false, false, false, true,
                  false, true, true, false, false, true,
                  false, true, false, false, true, true,
                  false, false, true, false, true, false,
                  true, false, true, false, true, true,
                  true, true, true, false, true, true};

    cout<<how_many(A, 1, 1);

    return 0;
}