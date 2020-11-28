//
//  main.cpp
//  Problem C (Conditional Statement -3)
//
//  Created by Ilyas Karimov on 26.11.20.
//


#include <iostream>
long long sum,x;
long long f(long long x){
    if(x<-4) return sum = x + 5;
    if(x>7) return sum = x*x*x + 2*x;
    else return sum = x*x - 3*x;
}
int main(int argc, const char * argv[]) {
    scanf("%lld", &x);
    printf("%lld", f(x));
    
}

