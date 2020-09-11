//
//  main.cpp
//  4730
//
//  Created by Ilyas Karimov on 9/10/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
int memoization [47]; //
int fib (int n){
    
    if (n == 0 || n == 1){
       return 1;
    }
    if (memoization[n] !=0){
        return memoization[n];
    }
    else{
        memoization[n] = fib(n-1) + fib(n-2);
        return memoization[n];
    }
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
}
