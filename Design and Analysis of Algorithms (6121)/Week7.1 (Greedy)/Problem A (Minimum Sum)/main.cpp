//  main.cpp
//  Problem A (Minimum Sum)
//
//  Created by Ilyas Karimov on 28.10.20.
//

#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;
int m[MAX],n[MAX], i;

int f(int a, int b){
    return a>b;
}

int main(int argc, const char * argv[]) {
    int num;
    long long res = 0;
    scanf("%d", &num);
    for(int i=0;i<num;i++) scanf("%d", &m[i]);
    for(int i=0;i<num;i++) scanf("%d", &n[i]);
    sort(m,m+num);
    sort(n,n+num,f);

    for(int i=0;i<num;i++) res += 1LL*m[i]*n[i];
    printf("%lld", res);
    
}
