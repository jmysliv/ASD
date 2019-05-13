#include <iostream>
using namespace std;

struct Huntinglist{
    Huntinglist *next;
    int predator;
    int prey;
};

struct pokemons{
    int value;
    pokemons *next;
};

int *relesethemall(Huntinglist *list, int n){
    pokemons **head = new pokemons*[n]; //w headzie value oznacza ilosc pokemonów na które poluje, 1 na poczatku oznacza ze nie da sie wykonac zadanie, a potem ze jeden pokemon został juz wyposzczony, 0 oznacza ze jest spokojny lub wyposzczono jego dwie ofiary
    for(int i=0; i<n; i++) {
        head[i]->value = 0;
        head[i]->next = NULL;
    }

    while(list!=NULL){
        head[list->predator]->value ++;
        pokemons *p = new pokemons;
        p->value = list->predator;
        p->next = head[list->prey]->next;
        head[list->prey]->next = p;
        list=list->next;
    }

    for(int i=0; i<n; i++) if(head[i]->value==1) return NULL;

    int *result = new int[n];
    int i=0;

    while(i!=n){
        int tmp = i;
        for(int j=0; j<n; j++){
            if(head[j]->value==0){
                result[i] = j;
                i++;
                head[j]->value = -1;
                pokemons *p = head[j]->next;
                while(p!=NULL){
                    if( head[p->value]->value==1) head[p->value]->value=0;
                    else if(head[p->value]->value>1) head[p->value]->value=1;
                    p=p->next;
                }
            }
        }
        if(tmp==i) return NULL;
    }
    return result;
}
int main() {

    return 0;
}