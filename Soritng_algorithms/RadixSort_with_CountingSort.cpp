#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
const int N=10, K=10;

int find_max(int tab[N]){
    int maks=tab[0];
    for(int i=1; i<N; i++){
        if(tab[i]>maks) maks=tab[i];
    }
    return maks;
}

void CountingSort(int A[N], int tab[N], int pomoc[N]){
    int B[N], C[K], D[N];
    for(int i=0; i<K; i++) C[i]=0;
    for(int i=0; i<N; i++) C[A[i]]++;
    for(int i=1; i<K; i++) C[i]+=C[i-1];
    for(int i=N-1; i>=0; i--){
        C[A[i]]--;
        B[C[A[i]]]=tab[i];
        D[C[A[i]]]=pomoc[i];
    }
    for(int i=0; i<N; i++){
        tab[i]=B[i];
        pomoc[i]=D[i];
    }
}

void RadixSort(int tab[N]){
    int d=0, maks=find_max(tab);
    while(maks>0){
        maks/=10;
        d++;
    }

    int pomoc[N];
    for(int i=0; i<N; i++) pomoc[i]=tab[i];

    for(int i=0; i<d; i++){
        int A[N];
        for(int j=0; j<N; j++){
            A[j]=pomoc[j]%10;
            pomoc[j]/=10;
        }
        CountingSort(A, tab, pomoc);

    }
}
int main() {
    int t[N];
    srand(time(NULL));
    for(int i=0; i<N; i++){
        t[i]=rand()%100;
        cout<<t[i]<<endl;
    }
    cout<<"***********************************************"<<endl;
    RadixSort(t);
    for(int i=0; i<N; i++){
        cout<<t[i]<<endl;
    }

    return 0;
}