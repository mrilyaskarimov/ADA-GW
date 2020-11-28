//
//  main.cpp
//  Problem B (Conditional statement - 2)
//
//  Created by Ilyas Karimov on 26.11.20.
//

#include <iostream>
long long sum,x;
long long f(long long x){
    if(x>10) return sum = x*x*x + 5*x;
    else return sum = x*x - 2x +4;
}
int main(int argc, const char * argv[]) {
    scanf("%lld", &x);
    printf("%lld", f(x));
    
}

