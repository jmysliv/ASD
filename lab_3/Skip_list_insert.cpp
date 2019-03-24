#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct node{
    int key;
    node **next;
};
struct Skiplist{
    node *first;
    node *last;
    int max_level;
};

int get_level(){
    int lvl=0;
    srand(time(NULL));
    while(rand()%100 < 50) lvl++;
    return lvl;
}
node * find(Skiplist *sl, int key){
    node * p=sl->first;
    for(int lvl=sl->max_level; lvl>=0; lvl--){
        while(key > p->next[lvl]->key) p=p->next[lvl];
    }
    p=p->next[0];
    if(p->key==key) return p;
    return NULL;
}

void insert(Skiplist *sl, int value){
    node **prev_tab;
    node *p=sl->first;
    for(int lvl=sl->max_level; lvl>=0; lvl--){
        while(value > p->next[lvl]->key){
            prev_tab[lvl] = p;
            p=p->next[lvl];
        }
    }
    node * q = new node;
    q->key=value;
    int n_lvl = get_level();
    if(n_lvl > sl->max_level){
        n_lvl=sl->max_level + 1;
        prev_tab[n_lvl]=sl->first;
        prev_tab[n_lvl]->next[n_lvl]=sl->last;
    }
    for(int i=n_lvl; i>=0; i--){
        q->next[i]=prev_tab[i]->next[i];
        prev_tab[i]->next[i] = q;
    }

}

int main() {

    return 0;
}