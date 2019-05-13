#include <iostream>
using namespace std;

struct HT{
    int *table;
    int size;
};

struct node{
    int value;
    node *next;
};

struct stack{
    node *top;
};

void init(stack *s){
    s->top=NULL;
}

bool isempty(stack *s){
    if(s->top==NULL) return true;
    return false;
}

void push(stack *s, int value){
    node *n = new node;
    n->value = value;
    n->next = s->top;
    s->top = n;
}

int pop(stack *s){
    node *n = s->top;
    s->top = s->top->next;
    return n->value;
}
int has(int x){
    return x*17;
}

void enlarge(HT *ht){
    HT *n = new HT;
    n->size = ht->size*2;
    n->table = new int [n->size];
    for(int i=0; i<n->size; i++) n->table[i]=-1;
    stack *s = new stack;
    init(s);
    for(int i=0; i<ht->size; i++){
        if(ht->table[i]>=0){
            int tmp = has(ht->table[i])%n->size;
            if(n->table[tmp]==-1) n->table[tmp] = ht->table[i];
            else push(s, ht->table[i]);
        }
    }

    while(!isempty(s)){
        int x = pop(s);
        int tmp = has(x)%n->size;
        for(int i=0; i<n->size; i++){
            tmp = (tmp + 1)%n->size;
            if(n->table[tmp]==-1){
                n->table[tmp] = x;
                break;
            }
        }
    }

}
int main() {

    return 0;
}