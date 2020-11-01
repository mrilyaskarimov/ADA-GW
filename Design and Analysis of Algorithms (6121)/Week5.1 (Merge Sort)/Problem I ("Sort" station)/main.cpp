//
//  main.cpp
//  Problem I ("Sort" station)
//
//  Created by Ilyas Karimov on 30.10.20.
//
#include <iostream>
#define MAX 100001

int main(int argc, const char * argv[]) {
    int n, M, max ,m[MAX], flag=0;
    scanf("%d %d", &n, &M);
    for(int i=0;i<n;i++){
        scanf("%d", &m[i]);
    }
    max = m[0];
    for(int i=0;i<n-1;i++){
        if(m[i+1]>max) max = m[i+1];
        else{
            if(max + m[i+1] > M) flag = 1;
        }
    }
    if(flag==0) puts("Yes");
    if(flag==1) puts("No");
}
