//
//  main.cpp
//  Problem H (Water)
//
//  Created by Ilyas Karimov on 04.11.20.
//

#include <iostream>
#include <algorithm>
#define MAX 1000000001
using namespace std;
int main(int argc, const char * argv[]) {
    int n,k, a[MAX], count=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n; i++){
        scanf("%d", &a[i]);
        if(a[i]>k) {
            puts("impossible");
            break;
        }
    }
    int j=n;
    sort(a, a+n);
    for(int i=0; i<n/2;i++){
        if(a[i]+a[j]<=k) count++;
        else count +=2;
        j--;
    }
    printf("%d", count);
        
    
    
}
