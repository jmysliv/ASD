#include <iostream>
using namespace std;
const int N=10;

bool dfs(bool tab[N][N], int i, int counter){
    if(counter==N) return true;
    for(int j=0; j<N; j++){
        if(tab[i][j] && dfs(tab, j, counter + 1)) return true;
    }
    return false;
}
bool hamilton_path(bool tab[N][N]){
    for(int i=0; i<N; i++){
        if(dfs(tab, i, 1)) return true;
    }
    return false;
}

void path_finder(int tab[N][N], bool used[N], int help[N], int solution[N], int i, int sum, int &min){
    if(i==N-1 && tab[help[i]][help[0]]!=-1){
            sum+=tab[help[i]][help[0]];
            if(sum<min){
                min=sum;
                for(int j=0; j<N; j++){
                    solution[j]=help[j];
                }
            }
            return;
    }
    for(int j=0; j<N; j++){
        if(tab[help[i]][j]!=-1 && !used[j]){
            used[j]=true;
            help[i+1] = j;
            path_finder(tab, used, help, solution, i+1, sum + tab[help[i]][j], min);
            help[i+1] = -1;
            used[j] = false;
        }
    }
    return;
}

int * komiwojazer(int tab[N][N]){ //-1 brak krawedzi, >0 -> waga
    int min=INT_MAX;
    int help[N];
    help[0]=0;
    int solution[N];
    solution[0]=0;
    bool used[N];
    used[0]=true;
    for(int i=1; i<N; i++){
        help[i]=-1;
        solution[i]=-1;
        used[i]=false;
    }
    path_finder(tab, used, help, solution, 0, 0, min);
    return solution;
}
int main() {

    return 0;
}