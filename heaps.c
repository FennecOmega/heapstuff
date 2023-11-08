#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

typedef struct heap{
    int elem[MAX];
    int last;
}heap;



bool smallChild(int a, int b);
void swap(int * a, int * b);
int rightChild(int index);
int leftChild(int index);
int parent(int index);
void displayArray(int arr[], int size);


void initHeap(heap * H);
void heapifyExist(int arr[], int size, int index);
void heapify(heap * H, int index);
int deleteMin(heap * H);
void insert(heap * H, int elem);
void makeNull(heap * H);
void heapsort(heap * H);

int main(){

int arr[MAX] = {12, 6, 3, 6, 32, 10, 7, 9, 5, 8, 9, 10, 11, 25, 23, 26, 18, 19, 23, 21};
heap H;
initHeap(&H);

int i;

for(i = 0; i < MAX; i++){
    insert(&H, arr[i]);
}


displayArray(H.elem, sizeof(H.elem)/4);

heapsort(&H);

printf("\n\n\n");

displayArray(H.elem, sizeof(H.elem)/4);

}

void displayArray(int arr[], int size){

    int i;
    
    printf("[");
    for(i = 0; i < size - 1; i++){
       printf("%d, ", arr[i]);
    }
    printf("%d]", arr[size-1]);

}

bool smallChild(int a, int b){
    return (a <= b) ? true : false; 
}
void swap(int * a, int * b){
    int c = *a;
    *a = *b;
    *b = c;
}
int rightChild(int index){
    return index * 2 + 2;
}
int leftChild(int index){
    return index * 2 + 1;
}
int parent(int index){
    return (index - 1) / 2;
}
void initHeap(heap * H){
    H->last = -1;
}

void heapify(heap * H, int index){
    int smallest = index;
    int LC = leftChild(index);
    int RC = rightChild(index);
    if (LC <= H->last && H->elem[LC] < H->elem[smallest])
      smallest = LC;
    if (RC <= H->last && H->elem[RC] < H->elem[smallest])
      smallest = RC;
    if (smallest != index)
    {
      swap(&H->elem[index], &H->elem[smallest]);
      heapify(H, smallest);
    }
}

int deleteMin(heap * H){
    swap(&H->elem[0], &H->elem[H->last--]);
    heapify(H, 0);

    return H->elem[H->last+1];
}
void insert(heap * H, int elem){

H->last++;
H->elem[H->last] = elem;
int i;
for(i = parent(H->last); i >= 0; i--){
    heapify(H, i);
}

}

void makeNull(heap * H){

}

void heapsort(heap * H){
int arr[20];
int i = 0;

int oldIndex = H->last;
while(H->last >= 0){
    arr[i] = deleteMin(H);
    i++;
}
H->last = oldIndex;

printf("\n\n\n");
displayArray(arr, 20);

}
