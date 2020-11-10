//
//  main.cpp
//  Problem B (Saucepands and lids)
//
//  Created by Ilyas Karimov on 03.11.20.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001
int a[MAX], b[MAX], i, j;

int main(int argc, const char * argv[]) {
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n;  i++) scanf("%d", &a[i]);
    for(int i=0; i<m;  i++) scanf("%d", &b[i]);
    sort(a, a+n);
    sort(b, b+m);
    for(i = j = 0; i < n, j < m; j++) if (a[i] <= b[j]) i++;
    printf("%d\n",i);
}
