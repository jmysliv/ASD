#include <iostream>
using namespace std;
struct node{
    int value;
    node *next;
};
struct stack{
    node * top;
};
struct queue{
    stack in;
    stack out;
};

void insert(queue q, int value){
    node *n = new node;
    n->value=value;
    n->next=NULL;
    if(q.in.top==NULL){
        q.in.top = n;
        q.out.top = n;
    }
    else{
        q.in.top-> next = n;
        q.in.top = n;
    }
}
int get(queue q){
    int v = q.out.top->value;
    node *tmp = q.out.top;
    q.out.top = q.out.top->next;
    delete tmp;
    return v;
}
int main() {

    return 0;
}