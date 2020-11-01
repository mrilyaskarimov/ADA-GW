//
//  main.cpp
//  Problem H (Count the triplets)
//
//  Created by Ilyas Karimov on 31.10.20.
//

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
int a[MAX], b[MAX], c[MAX], s;
int my_lower_bound (int *m, int start, int end, int x){
    while(start<end){
        int mid = (start + end) /2;
        if(x <= m[mid]) end = mid;
        else start = mid + 1;
    }
    return start;
}
int my_upper_bound (int *m, int start, int end, int x){
    while(start < end){
        int mid = (start + end)/2;
        if (x>=m[mid]) start = mid+1;
        else end = mid;
    }
    return start;
}
int main(int argc, const char * argv[]) {
    long long  res, res2, sum=0;
    scanf("%d", &s);

    for(int i=0; i<s; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<s; i++){
        scanf("%d", &b[i]);
    }
    for(int i=0; i<s; i++){
        scanf("%d", &c[i]);
    }
    sort(a, a+s);
    sort(b, b+s);
    sort(c, c+s);

    for(int i=0; i<s;i++){
        res = my_lower_bound(a, 0, s, b[i]);
        res2 = s - my_upper_bound(c, 0, s, b[i]);
//        printf("%lld %lld\n",res, res2);
        sum += res*res2;
    }
    printf("%lld", sum);
}



