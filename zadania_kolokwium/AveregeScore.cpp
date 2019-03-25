#include <iostream>
using namespace std;

int Partition(double tab[], int l, int p){
    double x = tab[p];
    int j=l-1;
    for(int i=l; i<p; i++){
        if(tab[i]<x){
            j++;
            swap(tab[j], tab[i]);
        }
    }
    j++;
    swap(tab[j], tab[p]);
    return j;
}

double select(double A[], int l, int p, int i){
    if(l==p) return A[l];
    int q=Partition(A, l, p);
    if(i==q+1) return A[q];
    if(i>q+1) return select(A, q+1, p, i);
    if(i<q+1) return select(A, l, q-1, i);
}

double AveregeScore(double A[], int lowest, int highest, int n){
    double min=select(A, 0, n-1, lowest);
    double max = select(A, 0, n-1, n-highest);
    double sum=0.0;
    for(int i=0; i<n; i++){
        if(A[i]<max && A[i]>min){
            sum+=A[i];

        }
    }
    return sum/(n-lowest-highest);
}
int main() {

    return 0;
}