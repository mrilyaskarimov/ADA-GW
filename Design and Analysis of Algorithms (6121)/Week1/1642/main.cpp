//
//  main.cpp
//  1642
//
//  Created by Ilyas Karimov on 9/10/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
 //n! is divided by n anyways. so, (n-1)! should be divisible by n. but some multiplication of dividents of factorial can make n.
// if n is prime, then no, if

    int factorial, count = 0;
    scanf("%d", &factorial);
    for (int i = 2; i*i <=  factorial; i++){
        if(factorial%i == 0) count++;
        
    }
    if (factorial ==1) printf("%s", "YES");
    else if (factorial ==4) printf("%s", "NO");
    else{
        if (count>0) printf("%s", "YES");
        else printf("%s", "NO");
        }
}
