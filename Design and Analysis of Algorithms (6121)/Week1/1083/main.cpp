//
//  main.cpp
//  1083
//
//  Created by Ilyas Karimov on 9/10/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
long long test(long long ai, long long n){
    if(n == 1) {
        return ai*ai%10000;
      
    }
    return ai*test(ai, n-1)%10000;
}
using namespace std;
int main(int argc, const char * argv[]) {
    long long ai, n;
    scanf("%lld %lld", &ai, &n);
    printf("%lld",test(ai,n));
    
    
}
