#include <iostream>
using namespace std;

struct node{
    int value;
    node *next;
};

node * find_last(node *p){
    while(p!=NULL && p->next!=NULL) p=p->next;
    return p;
}
void wyswietl(node *f){
    node *q;
    q=f;
    while(q!=NULL){
        cout<<q->value<<endl;
        q=q->next;
    }
    cout<<"**********************************************"<<endl;
}

void insert(node *&p, int x){
    node * q = new node;
    q->value=x;
    q->next=p;
    p=q;
}


node *Partition(node *&l, node *&p){
    int x=p->value;
    node *pivot=l;
    node *nowy_mniejszy=NULL;
    node *nowy_wiekszy=NULL;
    node *tmp=NULL;
    while(pivot!=p){
        if(pivot->value<x){
            if(nowy_mniejszy==NULL){
                nowy_mniejszy=pivot;
                l=nowy_mniejszy;
            }
            else{
                nowy_mniejszy->next=pivot;
                nowy_mniejszy=nowy_mniejszy->next;
            }

        }
        else{
            if(nowy_wiekszy==NULL){
                nowy_wiekszy=pivot;
                tmp=nowy_wiekszy;
            }
            else{
                nowy_wiekszy->next=pivot;
                nowy_wiekszy=nowy_wiekszy->next;
            }
        }
        pivot=pivot->next;
    }
    if(nowy_mniejszy!=NULL){
        nowy_mniejszy->next=p;
    }
    else{
        l=p;
    }
    nowy_mniejszy=p;
    p->next=tmp;
    if(nowy_wiekszy!=NULL) {
        nowy_wiekszy->next=NULL;
        p=nowy_wiekszy;
    }

    return nowy_mniejszy;
}

node * Quicksort(node *l, node *p){
    if(l!=NULL && l!=p){
        node *pivot=Partition(l, p);
        if(l!=pivot){
            node *tmp=l;
            while(tmp->next!=pivot) tmp=tmp->next;
            tmp->next=NULL;
            l=Quicksort(l, tmp);
            find_last(l)->next=pivot;
        }
        pivot->next=Quicksort(pivot->next, p);

    }
    return l;
}




int main() {
    node *p=NULL;
    insert(p, 4);
    insert(p , 1);
    insert(p , 5);
    insert(p , 3);
    insert(p , 2);
    insert(p, 10);
    insert(p, 7);
    wyswietl(p);
    node *q=;
    q=Quicksort(p, find_last(p));
    wyswietl(q);

    return 0;
}