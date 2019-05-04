#include <iostream>
using namespace std;
const int N=5;
//znaleźć ujście: 1) nie wychodzi od niego zadna krawedź 2) wszytskie pozostałe do niego wchodzą

int find_exit(bool tab[N][N]){
    bool flag=true;
    int suspect=-1;
    for(int i=0; i<N; i++){
        flag=true;
        for(int j=0; j<N; j++){
            if(tab[i][j]){
                flag=false;
                break;
            }
        }
        if(flag) {
            suspect=i;
            break;
        }
    }
    if(suspect==-1) return -1;
    for(int i=0; i<N; i++){
        if(!tab[i][suspect] && i!=suspect) return -1;
    }
    return suspect;
}

int main() {

    //TEST
    bool tab[N][N]={0, 1, 0, 1, 0,
                   0, 0, 0, 0, 1,
                   0, 1, 0, 0, 1,
                   0, 0, 0, 0, 1,
                   0, 0, 0, 0, 0};

    cout<<find_exit(tab);

    return 0;
}