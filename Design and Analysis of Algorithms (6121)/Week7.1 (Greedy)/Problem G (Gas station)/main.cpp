//
//  main.cpp
//  Problem G (Gas station)
//
//  Created by Ilyas Karimov on 04.11.20.
//

#include <iostream>
#include <algorithm>
#define MAX 10001

using namespace std;
int m[MAX];
int main(int argc, const char * argv[]) {
    int l,n, max=0;
    scanf("%d %d",&l,&n);
    for(int i=0;i<n;i++) scanf("%d", &m[i]);
    sort(m, m+n);
    
//    for(int i=0;i<n;i++) printf("%d", m[i]);
    max = l-m[n-1]+m[0];
//    printf("%d", max);
    for(int i=0;i<n-1;i++)  if(m[i+1] - m[i] > max) max = m[i+1] - m[i];
    
    printf("%.1lf", max/2.0);
}
