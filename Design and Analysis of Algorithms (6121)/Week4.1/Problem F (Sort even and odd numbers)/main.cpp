//
//  main.cpp
//  Problem F (Sort even and odd numbers)
//
//  Created by Ilyas Karimov on 10/11/20.
//

#include <iostream>
#define MAX 1001

int a[MAX], n;
int abs(int n)
{
    if(n>0) return n;
    else return -n;
}

int f(int a, int b){
    if(abs(a%2) != abs(b%2)) return abs(a%2) > abs(b%2);  // odd numbers come first, then even numbers
    if(abs(a%2 == 0)) return a>b; // if even numbers, decreasing order
    else return a < b;              // if odd numbers, increasing order.
}
int left(int i){
    return 2*i;
}
int right(int i){
    return 2*i+1;
    
}
void swap(int &i, int &j){
    int temp = i; i =j;  j = temp;
    
}
void heapify(int a[], int i, int n, int f(int a, int b)){
    int l = left(i); int r = right(i); int largest = 0;
    
    if(l<=n && f(a[i], a[l])) largest= l;
    else largest = i;
    if(r<=n && f(a[largest], a[r])) largest = r;
    
    if(largest!=i){
        swap(a[largest], a[i]);
        heapify(a, largest, n, f);
    }
}

void BuildHeap(int a[], int n, int f(int a, int b)){
    for(int i=n/2; i>0; i--){
        heapify(a, i, n, f);
    }
}
void HeapSort(int a[], int n, int f(int a, int b)){
    BuildHeap(a, n, f);
    for (int i = n; i >= 2; i--) {
    swap(a[1], a[i]);
    heapify(a, 1, i - 1, f);
    }
}


int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    
    HeapSort(a,n, f);
    for (int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    
    return 0;
}
