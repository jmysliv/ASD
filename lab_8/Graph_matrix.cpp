#include <iostream>
using namespace std;
const int N=5;
//Graf w macierzy sąsiedztwa. Sprawdzić dwudzielność i liczbe spójnych składowych. N-liczba wirzcholków

bool is_bipartite(bool tab[N][N]){
    int color[N];
    for(int i=0; i<N; i++) color[i]=0;

    color[0]=1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(tab[i][j]){
                if(color[j]==0) color[j]=(color[i]%2) + 1;
                if(color[j]!=((color[i]%2) + 1)) return false;
            }
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

int how_many(bool tab[N][N]){
    int parent[N], rank[N];
    init(parent, rank);
    int counter=N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(tab[i][j]){
                Union(parent, rank, i, j, counter);
            }
        }
    }
    return counter;
}
int main() {
    //TEST
    bool tab[N][N]={0, 1, 0, 0, 0,
                    1, 0, 0, 0, 0,
                    0, 0, 0, 0, 0,
                    0, 0, 0, 0, 1,
                    0, 0, 0, 1, 0};
    cout<<is_bipartite(tab)<<endl;
    cout<<how_many(tab);

    return 0;
}