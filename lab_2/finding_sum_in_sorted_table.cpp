#include <iostream>
using namespace std;
const int N;

bool two_elements(int tab[N], int x){
    int i=0, j=N-1;
    while(i!=j){
        if(tab[i] + tab[j] == x) return true;
        else if(tab[i] + tab[j] > x) j--;
        else i++;
    }
    return false;
}
int main() {

    return 0;
}