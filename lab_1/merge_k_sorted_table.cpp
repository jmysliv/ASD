#include <iostream>
const int N, K;
struct sorted_table{
    int tab[];
    int size;
};
sorted_table tab[K];

void Merge(int t[], int start, int sr, int stop){
    int tp=new int [stop-start+1];
    int i=start, j=sr+1, k=0;
    while(i<=sr && j<=stop){
        if(t[i]<t[j]) tp[k++]=t[i++];
        else tp[k++] = t[j++];
    }
    while(i<=sr) tp[k++] = t[i++];
    while(j<=stop) tp[k++] = t[j++];
    for(int l=0; l<stop-start+1; l++){
        t[start+l] = tp[l];
    }
}
void przesun(int usun, int poczatki[], int &obecnie){
    for(int i=usun; i<obecnie, i++){
        poczatki[i]=poczatki[i+1];
    }
    obecnie--;
}

void zadanie(sorted_table tab[K]){
    int t[N], poczatki[K+1], j=1, k=0;
    poczatki[0]=0;poczatki[K]=N;
    for(int i=0; i<N; i++){
        if(k == tab[j].size){
            poczatki[j]=i;
            j++;
            k=0;
        }
        t[i] = tab[j].tab[k];
        k++;
    }
    int c=0, obecnie=K;
    while(obecnie!=1){
        Merge(t, poczatki[c], poczatki[c+1] - 1, poczatki[c+2] -1);
        przesun(c+1, poczatki, obecnie);
        if(c+2>obecnie) c=0;
        else c=c+2;
    }


}
int main() {

    return 0;
}