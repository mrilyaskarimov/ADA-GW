//
//  main.cpp
//  tests
//
//  Created by Ilyas Karimov on 9/19/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
int fib (int num){
    if(num == 0) return 2;
    if(num == 1) return 5;
    return fib(num-1) + fib(num-2);
}
int main(int argc, const char * argv[]) {
    int num = 33;
    printf("%d", fib(num));
}

