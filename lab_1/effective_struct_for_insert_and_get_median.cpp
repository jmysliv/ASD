#include <iostream>
using namespace std;
const int N;

struct kopiec{
    int t[N];
    int size=t[0];
};
struct two_heaps{
    kopiec min_heap;
    kopiec max_heap;
    int ilosc = min_heap.size + max_heap.size;
};
int left(int i){
    return i*2;
}
int right(int i){
    return i*2 +1;
}
int size(int t){
    return t[0];
}
void swap(int &a, int &b){
    a=a+b; b=a-b; a=a-b;
}
int parent(int a){
    return a/2;
}
void heapify_max(int t[], int i){
    int l=left(i);
    int r=right(i);
    int max=i;
    if(l<=size(t) && t[l]>t[max]) max=l;
    if(r<=size(t) && t[r]>t[max]) max=r;
    if(max!=i) {
        swap(t[max], t[i]);
        heapify_max(t, max);
    }
}
void heapify_min(int t[], int i){
    int l=left(i);
    int r=right(i);
    int max=i;
    if(l<=size(t) && t[l]<t[max]) max=l;
    if(r<=size(t) && t[r]<t[max]) max=r;
    if(max!=i) {
        swap(t[max], t[i]);
        heapify_max(t, max);
    }
}
int getmax(int t[]){
    if(t[0]==0) return;
    int result = t[1];
    t[1] = t[t[0]];
    t[0]--;
    heapify_max(t, 1);
    return result;
}
int getmin(int t[]){
    if(t[0]==0) return;
    int result = t[1];
    t[1] = t[t[0]];
    t[0]--;
    heapify_min(t, 1);
    return result;
}
void insert_max(int t[], int el){
    if(t[0]==N-1) return;
    t[0]++;
    t[t[0]]=el;
    int i=t[0];
    while(i>1 && t[i]>t[parent[i]]){
        swap(t[i], t[parent(i)]);
        i=parent(i);
    }
}
void insert_min(int t[], int el){
    if(t[0]==N-1) return;
    t[0]++;
    t[t[0]]=el;
    int i=t[0];
    while(i>1 && t[i]<t[parent[i]]){
        swap(t[i], t[parent(i)]);
        i=parent(i);
    }
}

void insert(two_heaps k, int el){
    if(k.ilosc == 0){
        insert_max(k.max_heap.t, el);
        return;
    }
    if(el<k.max_heap.t[1]){
        insert_max(k.max_heap.t, el);
    }
    else{
        insert_min(k.min_heap.t, el);
    }
    if(k.min_heap.size==k.max_heap.size + 2){
        insert_max(k.max_heap.t, getmin(k.min_heap.t));
    }
    if(k.min_heap.size + 2==k.max_heap.size){
        insert_min(k.min_heap.t, getmax(k.max_heap.t));
    }
}
int Getmedian(two_heaps k){
    if(k.ilosc==0) return 0;
    if(k.ilosc%2==0){
        return (k.max_heap.t[1] + k.min_heap.t[1])/2;
    }
    if(k.min_heap.size>k.max_heap.size) return k.min_heap.t[1];
    else return k.max_heap.t[1];
}
int main() {

    return 0;
}
