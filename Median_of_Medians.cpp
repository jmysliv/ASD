#include <iostream>
using namespace std;
const int N=20;

int partition(int t[], int pivot, int rozmiar){
    int i=-1;
    for(int j=0; j<rozmiar; j++){
        if(t[j]<pivot){
            i++;
            swap(t[i], t[j]);
        }
    }
    return i+1;
}

int find_median(int t[], int p, int rozmiar){ //zalozenie ze sortujemy 5 liczb od p wlacznie
    int i, j, value;    //sortowanie przez wstawianie
    for (i = p+1; i < p+5 && i<rozmiar; i++)
    {
        value = t[i];
        for (j = i - 1; j >= p && t[j] > value; j--)
        {
            t[j + 1] = t[j];
        }
        t[j + 1] = value;
    }
    if(p+5<=rozmiar) return t[p+2];   //zwracanie mediany
    if((rozmiar-p)%2==1) return t[p+(rozmiar-p)/2];
    return (t[p - 1+(rozmiar-p)/2] + t[p+(rozmiar-p)/2])/2;
}
int mediana_median(int A[], int rozmiar){ //rozmiar tablicy, wywolanie dla A[N] : mediana_median(A, N)
    if(rozmiar<=5) return find_median(A, 0, rozmiar);   //warunek konca
    int i=0;
    int *tab = new int[((rozmiar-1)/5) + 1]; //tworzenie tablicy do ktorej zapiszemy mediany
    while(i*5<rozmiar){
       tab[i]=find_median(A, i*5, rozmiar);
       i++;
    }
    return mediana_median(tab, ((rozmiar-1)/5) +1);   //wywolanie rekurencyjne dla tablicy median
}

int find_k_element(int tab[], int k, int rozmiar, int p){
    int pivot=mediana_median(tab, rozmiar);
    int x=partition(tab, pivot, rozmiar);
    cout<<pivot<<"|"<<x<<"|"<<p<<"rozmiar: "<<rozmiar<<endl;
    if(k==(x+p)) return pivot;
    if(k>(x+p)) {
        int *t=new int[rozmiar-1-x];
        for(int i=0; i<rozmiar-1-x; i++) t[i]=tab[i+x+1];
        return find_k_element(t, k, rozmiar-1-x, x+1+p);
    }
    if(k<(x+p)){
        int *t=new int[x];
        for(int i=0; i<x; i++) t[i]=tab[i];
        return find_k_element(t, k, x, p);
    }

}
int main() {
    int tab[N]={1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 50, 9, 17, 16, 3, 5, 30, 8, 11, 13};
    cout<<find_k_element(tab, N/2, N, 0);
    return 0;
}