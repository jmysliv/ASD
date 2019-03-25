#include <iostream>
using namespace std;


//finds sum between index from and to in table in o(n)

int partition(int tab[], int l, int r){
    int pivot=tab[r];
    int j=l-1;
    for(int i=l; i<r; i++){
        if(tab[i]<pivot){
            j++;
            swap(tab[j], tab[i]);
        }
    }
    j++;
    swap(tab[r], tab[j]);
    return j;
}

int select(int tab[], int l, int r, int i){
    if(l==r) return l;
    int q = partition(tab, l, r);
    if(i==q) return tab[q];
    if(i<q) return select(tab, l, q-1, i);
    return select(tab, q+1, r, i);
}

int SumBetween(int tab[], int from, int to, int n){
    int min=select(tab, 0, n-1, from);
    int max=select(tab, 0, n-1, to);
    int sum=0;
    for(int i=0; i<n; i++){
        if(tab[i]<=max && tab[i]>=min)sum+=tab[i];
    }
    return sum;

}

int main() {
    int tab[10]={1, 2, 3, 4, 10, 8, 6, 7, 9, 5};
    cout<<SumBetween(tab, 2, 5, 10);

    return 0;
}
