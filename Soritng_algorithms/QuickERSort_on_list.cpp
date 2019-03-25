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

void insert_node(node *&f, node *n){
    n->next=f;
    f=n;
}

node * partition(node *&head){
    node * pivot= find_last(head);
    node * tmp=head;
    node *n=tmp->next;
    node * l=NULL;
    node *m=NULL;
    node *p=NULL;
    while(tmp!=pivot){
        if(tmp->value < pivot->value) insert_node(l, tmp);
        else if(tmp->value == pivot->value) insert_node(m, tmp);
        else insert_node(p, tmp);
        tmp=n;
        n=n->next;
    }
    insert_node(m, pivot);
    if(l!=NULL){
        head=l;
        find_last(l)->next=m;
        find_last(m)->next=p;
    }
    else{
        head=m;
        find_last(m)->next=p;
    }
    return m;
}

node *QuickerSort(node *head){
    if(head!=NULL){
        node *pivot=partition(head);
        if(head!=pivot){
            node *tmp=head;
            while(tmp->next!=pivot) tmp=tmp->next;
            tmp->next=NULL;
            head=QuickerSort(head);
            find_last(head)->next=pivot;
        }
        while(pivot==pivot->next) pivot=pivot->next;
        pivot->next=QuickerSort(pivot->next);
    }
    return head;
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
    insert(p, 1);
    insert(p, 5);
    wyswietl(p);
    node *q;
    q=QuickerSort(p);
    wyswietl(q);

    return 0;
}