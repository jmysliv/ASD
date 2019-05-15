#include <iostream>
using namespace std;

struct set{
    set *one;
    set *zero;
    bool ends;
};

void insert(set *s, string A, int i){
    if(s==NULL){
        s=new set;
        s->one=NULL;
        s->zero=NULL;
        s->ends=false;
    }
    if(A.length()==i+1) {
        s->ends=true;
        return;
    }
    if(A[i]=='0') insert(s->zero, A, i+1);
    else insert(s->one, A, i+1);
}

set* createset(string A[], int n){
    set *head = new set;
    head->one=NULL;
    head->zero=NULL;
    head->ends=false;

    for(int i=0; i<n; i++){
        insert(head, A[i], 0);
    }

    return head;
}

bool contains(set *a, string s){
    int i=0;
    while(s.length()>i){
        if(s[i]=='0') a=a->zero;
        else a=a->one;
        i++;
    }

    return a->ends;

}


int main() {

    return 0;
}