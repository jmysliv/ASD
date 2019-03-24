#include <iostream>
using namespace std;
const int k, N;
int left(int i){
    return i*2;
}
int right(int i){
    return i*2 +1;
}
int size(int t){
    return t[0];
}
void swap(int &a, int &b){
    a=a+b; b=a-b; a=a-b;
}
void heapify(int t[], int i){
    int l=left(i);
    int r=right(i);
    int max=i;
    if(l<=size(t) && t[l]>t[max]) max=l;
    if(r<=size(t) && t[r]>t[max]) max=r;
    if(max!=i) {
        swap(t[max], t[i]);
        heapify(t, max);
    }
}
void built(int t[]){
    for(int i=size(t)/2; i>0; i++){
        heapify(t, i);
    }
}
int getmax_addnew(int t[], /*pozostale tablice*/){
    int result=t[1];
    t[1]= ;//nastepny z tablicy elementu result; jesli go nie ma to t[1]=t[t[0]]; t[0]-- ;
    heapify(t, 1);
    return result;
}
void scal(/* k posortowanych malejaco tablic lub tablica wskaznikow na nie? */){
    int t[k+1]; t[0]=k;
    for(int i=1; i<=k; i++){
        t[i]=;//pierwsze elementy kolejnych tablic
    }
    built(t);
    int final_tab[N];
    for(int i=0; i<N; i++){
        final_tab[i]=getmax_addnew(t);
    }
}
int main() {

    return 0;
}