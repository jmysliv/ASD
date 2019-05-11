#include <iostream>
using namespace std;
const int MAX_LEVEL=10;

struct node{
    int value;
    int level;
    node **next;
};

struct skiplist{
    node *first;
    node *last;
};

skiplist merge(skiplist A, skiplist B){
    node **last_A;
    for(int i=0; i<MAX_LEVEL; i++) last_A[i] = A.first;
    node *p=A.first->next[0]; node *q=B.first->next[0];

    while(p!=A.last || q!=B.last){
        if(p->value < q->value){
            for(int i=0; i<p->level; i++){
                last_A[i]->next[i]=p;
                last_A[i]=p;
            }
            p=p->next[0];
        }
        else{
            for(int i=0; i<q->level; i++){
                last_A[i]->next[i]=q;
                last_A[i]=q;
            }
            q=q->next[0];
        }
    }

    for(int i=0; i<MAX_LEVEL; i++) last_A[i]->next[i] = A.last;

    return A;

}
int main() {

    return 0;
}