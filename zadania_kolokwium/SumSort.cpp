#include <iostream>
using namespace std;
// Sorts A[n^2] that Sums of n further elements are sorted non-descending
const int N=100;
struct sum{
    int value;
    int start;
};

void Insertion_sort_for_struct(sum tab[N]){
    for(int i=1; i<N; i++){
        int j=i-1;
        sum tmp=tab[i];
        while(j>=0 && tmp.value<tab[j].value){
            tab[j+1]=tab[j];
            j--;
        }
    }
}

void Sumsort(int A[], int B[], int N){
    sum *tab=new sum[N];
    for(int i=0; i<N; i++){
        int s=0;
        for(int j=0; j<N; j++){
            s+=A[i*N + j];
        }
        tab[i].value=s;
        tab[i].start=i*N;
    }
    Insertion_sort_for_struct(tab);
    int c=0;
    for(int i=0; i<N; i++){
        for(int j=tab[i].start; j<tab[i].start+N; j++){
            B[c]=A[j];
            c++;
        }
    }
}
int main() {

    return 0;
}