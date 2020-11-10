//
//  main.cpp
//  Problem F (Chocolate lover)
//
//  Created by Ilyas Karimov on 28.10.20.
//

#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, const char * argv[]) {
    int d, a, b;
    long long sum = 0;
    scanf("%d %d %d", &d, &a, &b);
    if(d%2==0) sum = (a+b)*d/2;
    if(d%2==1) sum = max(((d+1)/2)*a + b*(d/2), ((d+1)/2)*b + a*(d/2));
    printf("%lld", sum);
}
