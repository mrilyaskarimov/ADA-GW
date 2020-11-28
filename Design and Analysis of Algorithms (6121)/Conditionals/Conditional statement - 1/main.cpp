//
//  main.cpp
//  Conditional statement - 1
//
//  Created by Ilyas Karimov on 26.11.20.
//

#include <iostream>
long long sum,x;
long long f(long long x){
    if(x<5) return sum = x*x - 3*x +4;
    else return sum = x+7;
}
int main(int argc, const char * argv[]) {
    scanf("%lld", &x);
    printf("%lld", f(x));
    
}
