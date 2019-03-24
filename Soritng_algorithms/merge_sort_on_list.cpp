 #include <iostream>
using namespace std;
struct node{
    int value;
    node *next;
};

node *scal(node *p1, node *p2){
    if(p1==NULL) return p2;
    if(p2==NULL) return p1;
    if(p1->value < p2->value){
        p1->next=scal(p1->next, p2);
        return p1;
    }
    else{
        p2->next=scal(p1, p2->next);
        return p2;
    }
}

node * find_middle(node *p){
    node *q=p;
    while(p!=NULL && p->next!=NULL && p->next->next!=NULL){
        p=p->next->next;
        q=q->next;
    }
    return q;
}

node * merge_sort(node *p){


    node *q = find_middle(p)->next;
    find_middle(p)->next=NULL;
    if(find_middle(p)==p) return scal(p, q);
    p=merge_sort(p);
    q=merge_sort(q);
    return scal(p, q);


}
int main() {

    return 0;
}