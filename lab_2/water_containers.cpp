#include <iostream>
using namespace std;
const int N;

struct punkt{
    int x;
    int y;
};

struct pojemnik{
    punkt gorny;
    punkt dolny;
    int poj=abs(gorny.x - dolny.x)*abs(gorny.y - dolny.y);
};

pojemnik tab[N];

int current(pojemnik tab[N], int y){
    int field=0;
    for(int i=0; i<N; i++){
        if(tab[i].dolny.y<y){
            if(tab[i].gorny.y<y) field+=tab[i].poj;
            else field+=abs(y-tab[i].dolny.y)*abs(tab[i].gorny.x-tab[i].dolny.x);
        }
    }

    return field;
}

int zadanie(pojemnik tab[N], int water){
    int t[N];
    for(int i=0; i<N; i++) t[i]=tab[i].gorny.y;
    Sort(t);
    int counter=0, j=0;
    while(water>current(tab, t[j])){
        j++;
        counter++;
    }

    return counter;

}
int main() {

    return 0;
}
