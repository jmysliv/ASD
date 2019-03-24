#include <iostream>
using namespace std;
const int N;

int inversion(int t[]){
    int counter=0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(t[i]>t[j]) counter++;
        }
    }
    return counter;
}

void Merge(int t[], int start, int sr, int stop, int &counter) {
    int tp = new int[stop - start + 1];
    int i = start, j = sr + 1, k = 0;
    while (i <= sr && j <= stop) {
        if (t[i] < t[j]) tp[k++] = t[i++];
        else {
            t[k++] = t[j++];
            counter=counter+(sr-i+1);
        }
    }
    while (i <= sr) tp[k++] = t[i++];
    while (j <= stop) tp[k++] = t[j++];
    for (int l = 0; l < stop - start + 1; l++) {
        t[start + l] = tp[l];
    }
}
int counter=0;

void Mergesort(int t[], int start, int stop, int &counter){
    int sr;
    if(start!=stop){
        sr=(start+stop)/2;
        Mergesort(t, start, sr, counter);
        Mergesort(t, sr+1, stop, counter);
        Merge(t, start, sr, stop, counter);
    }
}

int main() {

    return 0;
}