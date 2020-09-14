//
//  main.cpp
//  5198
//
//  Created by Ilyas Karimov on 9/10/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
long long expo(long long a, long long b, long long m ){
    if(b==0) return 1;
    if(b%2==0) return expo((a*a)%m,b/2,m);
    return (a* expo(a,b-1, m))%m;
// meselen 2 ustu 8 100 mod tapmalisan, 8 2 e tam bolmek olursa, gotur x ni vur ozune ve 8 i 2 defe azalt, but bolmek olmursa, meselen 7 dirse, -1 cix b den amma 2 ni expo ya cagir ki cut olsun. eminem ki, bunu sonra anlamaycam. breh breh :')  IK
    
}
int main(int argc, const char * argv[]) {
    long long x, n ,m;
    scanf("%lld %lld %lld", &x, &n, &m );
    printf("%lld", expo(x,n,m));
}
