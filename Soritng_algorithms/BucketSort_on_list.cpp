#include <iostream>
using namespace std;
const int K=10;
struct node{
    node* next;
    double value;
};
void wyswietl(node *f){
    node *q;
    q=f;
    while(q!=NULL){
        cout<<q->value<<endl;
        q=q->next;
    }
    cout<<"**********************************************"<<endl;
}

void insert_value(node *&p, double x){
    node * q = new node;
    q->value=x;
    q->next=p;
    p=q;
}

void insert(node *&first, node* n){
    if(first==NULL || n->value < first->value) {
        n->next=first;
        first = n;

    }
    else{
        node *tmp=first->next;
        node *prev=first;
        while(tmp!=NULL && n->value > tmp->value){
            prev=tmp;
            tmp=tmp->next;
        }
        prev->next=n;
        n->next=tmp;
    }
}
int list_lenght(node *f){
    int counter=0;
    while(f!=NULL){
        counter++;
        f=f->next;
    }
    return counter;
}

void Bucketsort(node * list){ //przedział (0, 10)
    int n=list_lenght(list);
    node **B=new node*[n*10];
    for(int i=0; i<n*10; i++){
        B[i]=NULL;
    }
    node *tmp=list->next;
    node* p;
    while(tmp!=NULL){
        p=tmp->next;
        insert(B[(int)(n*tmp->value)], tmp);
        tmp=p;
    }
    p=list;
    for(int i=0; i<n*10; i++){
        tmp=B[i];
        if(tmp!=NULL){
            p->next=tmp;
            while(tmp!=NULL){
                p=tmp;
                tmp=tmp->next;
            }
        }
    }
}
int main() {
    node *p=NULL;
    insert_value(p, 3);
    insert_value(p, 4);
    insert_value(p , 1);
    insert_value(p , 5);
    insert_value(p , 3);
    insert_value(p , 2);
    insert_value(p, 0.2);
    insert_value(p, 7);
    insert_value(p, 9); // jest to wartownik i nie zostanie posortowany
    wyswietl(p);
    Bucketsort(p);
    wyswietl(p);
    return 0;
}