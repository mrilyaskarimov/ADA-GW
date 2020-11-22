//
//  main.cpp
//  Problem H (Water)
//
//  Created by Ilyas Karimov on 04.11.20.
//

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
long long a[MAX];
int main(int argc, const char * argv[]) {
    long long n,k, count=0, flag =0, i=0;
    scanf("%lld %lld",&n,&k);
    for(int i=0;i<n; i++){
        scanf("%lld", &a[i]);
        if(a[i]>k) flag=1;
    }
    sort(a, a+n);
    long long j=n-1;

    while(i<=j){
        if(a[i]+a[j]<=k){
            i++;
            j--;
        }
        else j--;
        count++;
    }
    if(flag) puts("Impossible");
    else printf("%lld", count);
}
