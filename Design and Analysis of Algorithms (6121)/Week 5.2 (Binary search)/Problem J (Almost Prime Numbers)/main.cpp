//
//  main.cpp
//  Problem J (Almost Prime Numbers)
//
//  Created by Ilyas Karimov on 31.10.20.
//

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAX 1000001
char primes[MAX];
long long l, h, ptr, m[MAX];

void gen_primes(){
    int i, j;
    for (i = 0; i < MAX; i++) primes[i] = 1;
    for (i = 2; i <= sqrt(1.0*MAX); i++)
        if (primes[i])
            for (j = i * i; j < MAX; j += i) primes[j] = 0;
}
long long my_upper_bound (long long *m, int start, int end, long long x){
    while(start < end){
        int mid = (start + end)/2;
        if (x>=m[mid]) start = mid+1;
        else end = mid;
    }
    return start;
}
int main() {
    gen_primes();
    
    for (int i = 2; i < MAX; i++)
        if (primes[i]){
            long long temp = 1L * i*i;
            while (temp < 1L * MAX*MAX){
                m[ptr++] = temp;
                temp *= i;
            }
        }
    sort(m, m + ptr);
    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%lld %lld", &l, &h);
        printf("%d\n", (my_upper_bound(m, 0,  ptr, h) - my_upper_bound(m, 0, ptr, l - 1)));
    }
}
