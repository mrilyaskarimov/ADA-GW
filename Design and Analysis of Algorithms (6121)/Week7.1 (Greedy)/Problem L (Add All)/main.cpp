//
//  main.cpp
//  Problem L (Add All)
//
//  Created by Ilyas Karimov on 11.11.20.
//

#include <cstdio>
#include <algorithm>
#include <set>
#define MAX 100001

using namespace std;
multiset<long long> cost;

long long m[MAX];
int main(void)
{
    long long  num,el, sum=0;
    scanf("%lld", &num);
    for(int i=0;i<num;i++){
        scanf("%lld", &el);
        cost.insert(el);
    }
    
    
    
    for (multiset<long long>:: iterator it=cost.begin(); it!=cost.end(); ){
        it=cost.begin();
        long long f = *it;
        cost.erase(*it);
        printf("f: %lld\n", f);
        it=cost.begin();
        long long s = *it;
        cost.erase(*it);
        printf("s: %lld\n", s);
        printf("s+f: %lld\n", s+f);
        cost.insert(s+f);
        sum += s+f;
        ++it;
    }
    printf("%lld", sum);
}
