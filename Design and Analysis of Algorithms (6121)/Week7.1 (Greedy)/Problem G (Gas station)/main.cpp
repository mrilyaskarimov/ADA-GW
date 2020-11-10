//
//  main.cpp
//  Problem G (Gas station)
//
//  Created by Ilyas Karimov on 04.11.20.
//

#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;
int m[MAX];
int main(int argc, const char * argv[]) {
    int l,n, max=0;
    scanf("%d %d",&l,&n);
    for(int i=0;i<n;i++) scanf("%d", &m[i]);
    sort(m, m+n);
    for(int i=0;i<n-1;i++)
        if(m[i+1] - m[i] > max) max = m[i+1] - m[i];
    printf("%.1lf", (float)max/2);
}
