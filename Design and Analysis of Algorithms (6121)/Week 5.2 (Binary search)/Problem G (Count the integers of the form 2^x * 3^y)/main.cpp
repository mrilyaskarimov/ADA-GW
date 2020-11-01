//
//  main.cpp
//  Problem G (Count the integers of the form 2^x * 3^y)
//
//  Created by Ilyas Karimov on 31.10.20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000000000000

using namespace std;
vector <long long> v;

void preprocess(){
    long long x = 1 , y = 1;
    while(x<MAX){
        while(x*y <MAX){
            v.push_back(x*y);
            y *=3;
        }
        x *=2;
        y = 1;
    }
    sort(v.begin(), v.end());
}

int main(int argc, const char * argv[]) {
    long long a, b, res;
    preprocess();
    while(scanf("%lld %lld", &a, &b) == 2){
        res = upper_bound(v.begin(), v.end(), b) - upper_bound(v.begin(), v.end(), a-1);
        printf("%lld", res);
    }
    
}
