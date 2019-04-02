#include <iostream>
using namespace std;
const int M=15;
const int N=10;

//implementacja tablicy asocjacyjnej z adresowaniem otwartym
struct Data{
    int licznik;
    int value;
};
struct key{
    int value;
    Data *data1;
    bool is_free;
    bool deleted;
};

int Hash2(int x, int i){
    return (abs(x)+i)%M;
}

void show_array(key *tab[M]){
    for(int i=0; i<M; i++){
        cout<<tab[i]->value<<"|"<<tab[i]->deleted<<"|"<<tab[i]->is_free<<endl;
    }
    cout<<"********************************"<<endl;
}

void init(key *tab[M]){
    for(int i=0; i<M; i++){
        tab[i] = new key;
        tab[i]->is_free=true;
        tab[i]->deleted=false;
        tab[i]->value=0;
        tab[i]->data1==nullptr;
    }
}
void insert(key *tab[M], int value, Data *d){
    for(int i=0; i<M; i++){
        if(tab[Hash2(value, i)]->is_free) {
            tab[Hash2(value, i)]->value=value;
            tab[Hash2(value, i)]->is_free=false;
            tab[Hash2(value, i)]->data1 = d;
            break;
        }
    }
}

int find(key *tab[M], int k){
    for(int i=0; i<M; i++){
        if(tab[Hash2(k, i)]->is_free && !tab[Hash2(k, i)]->deleted) return -1;
        if(tab[Hash2(k, i)]->value==k && !tab[Hash2(k, 1)]->deleted) return Hash2(k, i);
    }
    return -1;
}

void remove(key *tab[M], int k){
    int adr = find(tab, k);
    tab[adr]->deleted=true;
    tab[adr]->is_free=true;
}

void repair(key *tab[M]){
    Data *pom[M];
    int end=-1;
    for(int i=0; i<M; i++){
        if(!tab[i]->is_free){
            int kn=Hash2(tab[i]->value, 0);
            if(kn!=i){
                if(tab[kn]->deleted && tab[kn]->is_free){
                    tab[kn]->value=tab[i]->value; tab[kn]->is_free=false; tab[kn]->deleted=false; tab[kn]->data1=tab[i]->data1;
                }
                else{
                    pom[end++]=tab[i]->data1;
                }
                tab[i]->value=0;tab[i]->deleted=true; tab[i]->is_free=true; tab[i]->data1= nullptr;
            }
        }
    }
    for(int i=0; i<=end; i++) insert(tab, pom[i]->value, pom[i]);
    for(int i=0; i<M; i++) tab[i]->deleted=false;
}

//mamy nie posortowana tablice A[M], na ile sposobów można przedstawić
//x jako sumę A[i]+A[j] takiego że i<j.

int number(int A[N], int x){
    Data *tmp;
    key *tab[M];
    init(tab);
    int counter=0;
    for(int i=0; i<N; i++){
        if(find(tab, x-A[i])!=-1){
            counter+=tab[find(tab, x-A[i])]->data1->licznik;
        }
        if(find(tab, A[i])!=-1) tab[find(tab, A[i])]->data1->licznik++;
        else{
            tmp= new Data;
            tmp->value=A[i]; tmp->licznik=1;
            insert(tab, tmp->value, tmp);
        }

    }

    return counter;
}
int main() {

    int A[N]={2, 5, 3, 4, 4, 10, 2, 7, 9, 1};
    cout<<number(A, 8);

    return 0;
}