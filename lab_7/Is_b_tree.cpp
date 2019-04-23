#include <iostream>
using namespace std;
const int T=2;
const int N= 2*T - 1;

struct node {
    int n; // liczba kluczy zawarta w węźle
    int key[N]; // tablica kluczy w węźle
    node* child[N+1]; // wskaźniki do synów węzła
    bool leaf; // czy węzeł jest liściem
};


bool is_b_tree(node *p, bool is_root, int min, int max, int height,  int *max_height){  //is_b_tree(p, true, MIN_INT, MAX_INT, 0, -1)
    if(p==NULL) return true;
    if(!is_root && (p->n<T-1 || p->n>N)) return false;
    int tmp=min;
    for(int i=0; i<p->n; i++){
        if(p->key[i]<min || p->key[i]>max) return false;
        if(p->key[i]<tmp) return false;
        tmp=p->key[i];
    }
    if(p->leaf){
       if(*max_height==-1) *max_height=height;
       else if(height!=*max_height) return false;
       return true;
   }
   tmp=min;
   for(int i=0; i<p->n; i++){
       if(p->child[i]==NULL) return false;
       if(!is_b_tree(p->child[i], false, tmp, p->key[i], height + 1, max_height)) return false;
       tmp = p->key[i];
   }
   if(!is_b_tree(p->child[p->n], false, tmp, max, height + 1, max_height)) return false;
   return true;
}

int main() {

    return 0;
}