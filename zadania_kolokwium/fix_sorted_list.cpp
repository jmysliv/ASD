#include <iostream>
using namespace std;
struct node{
    node* next;
    int value;
};

void insert_up(node* &f, int x){
     node *n=new node;
     n->value=x;
     n->next=NULL;
     node *tmp=f->next;
     node *p=f;
     if(x<f->value){
         n->next=f;
         f=n;
     }
     else{
         while(x>tmp->value){
             p=tmp; tmp=tmp->next;
         }
         p->next=n;
         n->next=tmp;
     }
}
void insert_down(node* &f, int x){
    node *n=new node;
    n->value=x;
    n->next=NULL;
    node *tmp=f->next;
    node *p=f;
    if(x>f->value){
        n->next=f;
        f=n;
    }
    else{
        while(x<tmp->value){
            p=tmp; tmp=tmp->next;
        }
        p->next=n;
        n->next=tmp;
    }
}
int lenght(node* f){
    int counter=0;
    while(f!=NULL){
        f=f->next;
        counter++;
    }
    return counter;
}
bool is_up(node * first){ //Z: list lenght>3
    int up=0, down=0;
    node *tmp=first->next;
    while(up<2 && down<2){
        if(tmp->value > first->value) up++;
        else down++;
    }
    if(up>down) return true;
    return false;
}

node* fixSortedList(node *f){ //z: lenght>=2
    node *tmp=f;
    int x;
    if(lenght(f)==3){
        x=f->value;
        f=f->next;
        delete(tmp);
        insert_up(f, x);
        return f;
    }
    node* wart=new node;
    wart->next=f;
    node *p=f->next;
    node *q=p->next;
    f=wart;
    if(is_up(f)){
        while(p->value > tmp->value){
            f=tmp; tmp=p; p=q; q=q->next;
        }
        if(q->value > tmp->value){
            tmp->next=q;
            x=p->value;
            delete(p);
            f=wart->next;
            delete(wart);
            insert_up(f, x);
            return f;
        }
        f->next=p;
        x=tmp->value;
        delete(tmp);
        f=wart->next;
        delete(wart);
        insert_up(f, x);
        return f;
    }
    while(p->value < tmp->value){
        f=tmp; tmp=p; p=q; q=q->next;
    }
    if(q->value < tmp->value){
        tmp->next=q;
        x=p->value;
        delete(p);
        f=wart->next;
        delete(wart);
        insert_down(f, x);
        return f;
    }
    f->next=p;
    x=tmp->value;
    delete(tmp);
    f=wart->next;
    delete(wart);
    insert_down(f, x);
    return f;

}


int main() {



    return 0;
}