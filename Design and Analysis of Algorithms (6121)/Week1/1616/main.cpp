// 100%
//  main.cpp
//  1616
//
//  Created by Ilyas Karimov on 9/10/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//
// Trial division: To test if n is prime, one can check for every k≤ sqrt (n) if k divides n. If no divisor is found, then n is prime.
#include <iostream>
#include <math.h>

using namespace std;
int main(int argc, const char * argv[]) {
    int num, count = 0;
    
    scanf("%d", &num);
    for (int i = 2; i <= sqrt(num); i++){
        if(num%i == 0){
            count += 1;
            break;
        }
    }
    if(count == 0){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}
