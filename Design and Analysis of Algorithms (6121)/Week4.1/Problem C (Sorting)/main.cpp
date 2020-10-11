//
//  main.cpp
//  Problem C (Sorting)
//
//  Created by Ilyas Karimov on 10/10/20.
//

#include <iostream>
#define MAX 1001
int n, a[MAX], i;
int left (int i){
    return 2*i;
}
int right (int i){
    return 2*i+1;
}
void swap (int &i, int &j){
    int temp = i; i = j; j = temp;
}
void heapify(int a[], int i, int n){
    int largest = 0, l = left(i), r = right(i);
    
    if(l<=n && a[l] > a[i]) largest = l;
    else largest = i;
    if(r<=n && a[r] > a[largest]) largest = r;
    
    if(largest !=i){
        swap(a[i], a[largest]);
        heapify(a, largest,n);
    }
}

void BuildHeap(int a[], int n){
    for (int i = n / 2; i > 0; i--) {
        heapify(a, i, n);
    }
}
void HeapSort(int a[], int n){
    BuildHeap(a, n);
    for (int i = n; i >= 2; i--) {
    swap(a[1], a[i]);
    heapify(a, 1, i - 1);
    }
}


int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }

    HeapSort(a, n);
    for(int i=1;i<=n;i++){
        printf("%d ", a[i]);
    }
}
