//
//  main.cpp
//  Problem I (Minimum increments)
//
//  Created by Ilyas Karimov on 31.10.20.
//

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000001
long long m[MAX], c[MAX], n;
long long sum=0;
bool f(long long start){
    for(int i=0; i<n;i++) c[i] = start++;
    for(int i=0;i<n;i++) if(m[i]>c[i]) return 0;
    return 1;
}
int main(int argc, const char * argv[]) {
    scanf("%lld", &n);
    long long max =0, start , end;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &m[i]);
        if(m[i]>max) max=m[i];
    }
    start = 0;
    end = max;
    while(start < end){
        long long mid = (start+end)/2;
        if(f(mid)==1) end = mid;
        else start = mid + 1;
    }
    for(int i=0;i<n;i++) {
        c[i] = start++;
        sum += c[i]-m[i];
    }
    printf("%lld", sum);
    return 0;
}
