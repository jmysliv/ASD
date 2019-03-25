#include <iostream>
using namespace std;
struct Pupil{
    int group;  //1-blue, 0-green
    Pupil *next;
};
int lenght(Pupil * f){
    int counter=0;
    while(f!=NULL){
        counter++;
        f=f->next;
    }
    return counter;
}
int DistanceToIdeal(Pupil *f){  //first green, then blue
    int sum=0;
    int n=lenght(f)/2;
    int counter=0;
    while(counter<n){
        if(f->group==1) sum+=n-counter;
        counter++;
        f=f->next;
    }
    counter=1;
    while(f!=NULL){
        if(f->group==0) sum+=counter;
        counter++;
        f=f->next
    }
    return sum*2;
}
int main() {

    return 0;
}