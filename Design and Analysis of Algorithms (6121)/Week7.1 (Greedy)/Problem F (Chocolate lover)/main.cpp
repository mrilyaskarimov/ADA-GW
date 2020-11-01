//
//  main.cpp
//  Problem F (Chocolate lover)
//
//  Created by Ilyas Karimov on 28.10.20.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int d, a, b, sum = 0;
    scanf("%d %d %d", &d, &a, &b);
    if(d%2==1){
        if(a>b) sum +=a;
        else sum +=b;
    }
    d = d/2;
    while(d--){
        sum += a+b;
    }
    printf("%d", sum);
}
