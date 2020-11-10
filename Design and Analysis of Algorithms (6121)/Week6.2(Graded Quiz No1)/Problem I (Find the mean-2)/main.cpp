//
//  main.cpp
//  Problem I (Find the mean-2)
//
//  Created by Ilyas Karimov on 04.11.20.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100000001

priority_queue<long long > pqmx;
priority_queue<long long,vector<long long>,greater<long long> > pqmn;
    

int main(int argc, const char * argv[]) {
    long long val, count=0;
    while(scanf("%lld", &val)==1){
        if(pqmn.empty()) pqmn.push(val);
        else{
            if(val>= pqmn.top()) pqmn.push(val);
            else pqmx.push(val);
        }
        
        if(pqmn.size()-pqmx.size()>1){
            pqmx.push(pqmn.top());
            pqmn.pop();

                    
        }
        else if(pqmx.size()>pqmn.size()){
            pqmn.push(pqmx.top());
            pqmx.pop();
        }
        
        if(count%2==0) printf("%lld\n", pqmn.top());
        if(count%2==1) printf("%lld",((pqmn.top()+pqmx.top())/2));
        count++;
    }
}

