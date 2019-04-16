#include <iostream>
using namespace std;
const int COUNT=10;
struct node{
    int value;
    node *right;
    node *left;
    node *parent;
    bool isred;
    int nearest_leaf;
};
void insert(node *&p, int k, node *tmp){    //insert(p, k, NULL)
    if(p==NULL){
        p=new node;
        p->left=NULL; p->right=NULL; p->parent =tmp;
        p->value=k;
    }
    else if(p->value>k){
        tmp=p;
        insert(p->left, k, tmp);
    }
    else{
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
    if(root->isred) cout<<"#";
    cout<<root->value<<"\n";

    // Process left child
    show(root->left, space);
}
int max_len(node *root){
    if(root==NULL) return 0;
    if(max_len(root->left) > max_len(root->right)) return max_len(root->left) + 1;
    return max_len(root->right) + 1;
}
int min_len(node *root){
    if(root==NULL) return 0;
    int distance;
    if(min_len(root->left) < min_len(root->right)) distance = min_len(root->left) + 1;
    distance = min_len(root->right) + 1;
    root->nearest_leaf=distance;
    return distance;
}
bool isRb(node *root, int len){
    if(root==NULL){
        if(len==0) return true;
        return false;
    }
    if(root->parent->isred){
        root->isred=false;
        return isRb(root->left, len-1) && isRb(root->right, len-1);
    }
    if(root->nearest_leaf < len ) return false;
    if(root->nearest_leaf == len){
        root->isred=false;
        return isRb(root->left, len-1) && isRb(root->right, len-1);
    }
    else{
        root->isred=true;
        return isRb(root->left, len) && isRb(root->right, len);
    }

}
bool first(node *root){
    int len=max_len(root);
    len= (len +1)/2;
    root->isred=false;
    min_len(root);
    return isRb(root->left, len-1) && isRb(root->right, len-1);
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
    insert(p, 18, NULL);
    first(p);
    show(p, 5);


    return 0;
}