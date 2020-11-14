//
//  main.cpp
//  Problem O (Knapsack)
//
//  Created by Ilyas Karimov on 11.11.20.
//
#include <iostream>
#include <algorithm>
#define MAX 1001
int m[MAX];

using namespace std;
int f(int a, int b){
    return a>b;
}
int main() {
    int w, n;
    long long sum = 0;
    scanf("%d %d", &w, &n);
    for(int i=0;i<n;i++) scanf("%d", &m[i]);
    sort(m, m+n, f);
    
    for(int i=0;i<w;i++) sum+=1LL*m[i];
    printf("%lld", sum);
}
