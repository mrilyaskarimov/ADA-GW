//
//  main.cpp
//  Problem B (Max-hea[)
//
//  Created by Ilyas Karimov on 10/10/20.
//

#include <iostream>

#define MAX 1001
int a[MAX], n, i;

int left(int i){
    return 2*i;
}
int right(int i){
    return 2*i+1;
}
void swap(int &i, int &j){
    int temp = i; i = j; j = temp;
}
void heapify(int a[], int i, int n){
    int largest = 0, l = left(i), r = right(i);
    
    if(l<=n && a[l] > a[i]) largest = l;
    else largest = i;
    if(r<=n && a[l] > a[largest]) largest = r;
    
    if(largest !=i){
        swap(a[i], a[largest]);
        heapify(a, largest,n);
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for(int i =1 ;i<= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=n/2; i>0; i--){
        heapify(a, i, n);
    }
    for(int i=1; i<=n; i++){
        printf("%d ",a[i]);
    printf("\n");
    
}
