//
//  main.cpp
//  Problem H (Queue)
//
//  Created by Ilyas Karimov on 10/11/20.
//

#include <iostream>
#include <functional>
#include <queue>
#include <vector>

using namespace std;
int n, k, ti;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++) {
    scanf("%d",&ti);
    if (pq.size() != k){
        pq.push(ti);
        }
    else {
        long long temp = pq.top(); pq.pop();
        pq.push(temp + ti); }
    }
    
    while(pq.size() > 1) pq.pop();
    printf("%lld\n",pq.top());

}
