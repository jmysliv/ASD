#include <iostream>
using namespace std;
const int N=10;

struct Edge{
    int u, v;
    int w;
    Edge *next;
};
void makeset(int parent[N], int rank[N]){
    for(int i=0; i<N; i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int findset(int i, int parent[N]){
    if(i==parent[i]) return i;
    parent[i] = findset(parent[i], parent);
    return parent[i];
}

void Union(int parent[N], int rank[N], int &distance, Edge *edges){
    int k = findset(edges->u, parent);
    int j = findset(edges->v, parent);
    if(k==j) return;
    if(rank[k]>rank[j]){
        parent[j] = k;
    }
    else if(rank[j]>rank[k]){
        parent[k] = j;
    }
    else{
        parent[k] = j;
        rank[j]++;
    }
    distance+=edges->w;
}

Edge *sort(Edge *edges){
    Edge *p=edges->next;


    while(p!=NULL){
        Edge *tmp=edges;
        Edge *prev=NULL;
        while(tmp!=NULL && p->w > tmp->w){
            prev=tmp;
            tmp=tmp->next;
        }
        if(prev==NULL){
            tmp=p;
            p=p->next;
            tmp->next=edges->next;
            edges=tmp;
        }
        else{
            tmp=p;
            p=p->next;
            tmp->next=prev->next;
            prev->next=tmp;
        }
    }

    return edges;

}

int Mst(Edge *edges){
    edges = sort(edges);
    int parent[N];
    int rank[N];
    makeset(parent, rank);
    int distance = 0;
    while(edges!=NULL){
        Union(parent, rank, distance, edges);
    }
    return distance;
}

int main() {

    return 0;
}