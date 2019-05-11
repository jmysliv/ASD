#include <iostream>
using namespace std;
struct Cyclist{
    int id;
    int n_id;
};

void create_hash_table(int tab[], int n, Cyclist cyclist[]){
    for(int i=0; i<n; i++) tab[i]=-1;
    for(int i=0; i<n; i++){
        int x = cyclist[i].id%n;
        while(-1!=tab[x]){
            x=(x+1)%n;
        }
        tab[x]=cyclist[i].id;
    }
}

int index_maker(int x, int tab[], int n){   //tab zawiera cyclist id, funkcja zwraca numer rowerzysty w przediale o - n-1
    int i=x%n;
    while(x!=tab[i]){
        i=(i+1)%n;
    }
    return i;
}
void make_set(int sets[], int size[], int n){
    for(int i=0; i<n; i++) {
        sets[i]=i;
        size[i]=1;
    }
}

int find_set(int sets[], int x){
    if(sets[x]==x) return x;
    sets[x] = find_set(sets, sets[x]);
    return sets[x];
}

void union_sets(int sets[], int size[], int x, int y){      //x,y - reprezentanci
    if(size[x]>size[y]){
        sets[y] = x;
        size[x]+=size[y];
        size[y] = 0;
    }
    else{
        sets[x] = y;
        size[y]+=size[x];
        size[x] = 0;
    }
}

int smallest_group(Cyclist cyclist[], int n){
    int *sets = new int[n];
    int *size = new int[n];
    make_set(sets, size, n);
    int *tab = new int[n];
    create_hash_table(tab, n, cyclist);

    for(int i=0; i<n; i++){
        if(cyclist[i].n_id!=-1){
            union_sets(sets, size, find_set(sets, index_maker(cyclist[i].id, tab, n)), find_set(sets, index_maker(cyclist[i].n_id, tab, n)));
        }
    }

    int min=n;
    for(int i=0; i<n; i++){
        if(size[i]!=0 && size[i]<min) min=size[i];
    }

    return min;
}

int main() {

    //TEST
    Cyclist cyclist[10];
    cyclist[0].id=15;
    cyclist[0].n_id=12;
    cyclist[1].id=12;
    cyclist[1].n_id=193;
    cyclist[2].id=7;
    cyclist[2].n_id=18;
    cyclist[3].id=100;
    cyclist[3].n_id=69;
    cyclist[4].id=69;
    cyclist[4].n_id=-1;
    cyclist[5].id=20;
    cyclist[5].n_id=-1;
    cyclist[6].id=193;
    cyclist[6].n_id=-1;
    cyclist[7].id=6;
    cyclist[7].n_id=20;
    cyclist[8].id=18;
    cyclist[8].n_id=222;
    cyclist[9].id=222;
    cyclist[9].n_id=6;
    cout<<smallest_group(cyclist, 10);

    return 0;
}