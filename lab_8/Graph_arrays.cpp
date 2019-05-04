#include <iostream>
using namespace std;
const int N=5;
//Graf w liscie sąsiedztwa. Sprawdzić dwudzielność i liczbe spójnych składowych. N-liczba wirzcholków
struct node{
    int value;
    node *next;
};
bool is_bipartite(node *tab[N]){
    int color[N];
    for(int i=0; i<N; i++) color[i]=0;

    color[0]=1;
    for(int i=0; i<N; i++){
        node *p = tab[i];
        while(p!=NULL){
            if(color[p->value]==0) color[p->value]=(color[i]%2) + 1;
            else if(color[p->value]!=((color[i]%2) + 1)) return false;
            p=p->next;
        }
    }
    return true;
}

void init(int parent[N], int rank[N]){
    for(int i=0; i<N; i++){
        parent[i]=i;
        rank[i]=1;
    }
}

int find(int parent[N], int i){
    if(i==parent[i]) return i;
    parent[i] = find(parent, parent[i]);
    return parent[i];
}

void Union(int parent[N], int rank[N], int i, int j, int &counter){
    int k=find(parent, i);
    int l=find(parent, j);
    if(k==l) return;
    counter--;
    if(rank[k]<rank[l]){
        parent[k]=l;
    }
    else if(rank[l]<rank[k]){
        parent[l]=k;
    }
    else{
        rank[k]++;
        parent[l]=k;
    }
}

int how_many(node *tab[N]){
    int parent[N], rank[N];
    init(parent, rank);
    int counter=N;
    for(int i=0; i<N; i++){
        node *p=tab[i];
        while(p!=NULL){
            Union(parent, rank, i, p->value, counter);
            p=p->next;
        }
    }
    return counter;
}

//rozwiazanie dla listy krawędzi


int main() {

    return 0;
}