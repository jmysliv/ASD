#include <iostream>
using namespace std;
const int COUNT=10;
struct node{
    node *left;
    node *right;
    node *parent;
    int key;
    int r;
    int l;
};

void insert(node *&p, int k, node *tmp){    //insert(p, k, NULL)
    if(p==NULL){
        p=new node;
        p->left=NULL; p->right=NULL; p->parent =tmp;
        p->key=k;
        p->r=p->l=0;
    }
    else if(p->key>k){
        p->l++;
        tmp=p;
        insert(p->left, k, tmp);
    }
    else{
        p->r++;
        tmp =p;
        insert(p->right, k, tmp);
    }
}

void show(node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    show(root->right, space);

    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->key<<"\n";

    // Process left child
    show(root->left, space);
}

int find(node *p, int i){
    if(i==p->r + 1) return p->key;
    if(i<=p->r) return find(p->right, i);
    else return find(p->left, i-(p->r +1));
}
int how_many_greater(node *p){ //how_many_greater(p, 0)
    int sum=p->r;
    node *q = p;
    p=p->parent;
    while(p!=NULL){
        if(q==p->left){
            sum= sum + 1 + p->r;
        }
        q=p;
        p=p->parent;
    }
    return sum+1;
}
int main() {
    node *p=NULL;
    insert(p, 10, NULL);
    insert(p, 12, NULL);
    insert(p, 3, NULL);
    insert(p, 1, NULL);
    insert(p, 6, NULL);
    insert(p, 15, NULL);
    insert(p, 11, NULL);
    cout<<how_many_greater(p->left);

    return 0;
}