//
//  main.cpp
//  Problem J (Almost Prime Numbers)
//
//  Created by Ilyas Karimov on 31.10.20.
//

#include <iostream>
#define MAX 100001
char primes[MAX];
long long m[MAX];

void gen_primes(){
    int i, j;
    for (i = 0; i < MAX; i++) primes[i] = 1;
    for (i = 2; i*i < MAX; i++)
        if (primes[i])
                for (j = i * i; j < MAX; j += i) primes[j] = 0;
}
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
    gen_primes();
    for(int i=2; i< MAX; i++){
        if(primes[i]){
            long long temp = 1LL*i*i;
            while (temp < 1L * MAX*MAX){
                m[ptr++] = temp;
                temp *= i;
            }
        }
    }
    std::cout << "Hello, World!\n";
    return 0;
}
