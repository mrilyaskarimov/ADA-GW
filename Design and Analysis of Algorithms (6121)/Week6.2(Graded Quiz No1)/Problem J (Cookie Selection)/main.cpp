//
//  main.cpp
//  Problem J (Cookie Selection)
//
//  Created by Ilyas Karimov on 05.11.20.
//
#include <iostream>
#include <queue>
#include <vector>
#include <stdlib.h>

#define MAX 11
using namespace std;

priority_queue<long long> pqmx;
priority_queue<long long,vector<long long>,greater<long long> > pqmn;
char str[MAX];
int main(int argc, const char * argv[]) {
    long long count=0;
    int flag =0 ;
    while(scanf("%s", str) == 1){
        
            if(str[0] == '#'){
                if(count ==0) continue;
                
                if(flag ==1 ){
                    printf("%lld\n", pqmn.top());
                    pqmn.pop();
                    flag=0;
                }
                else if(count%2==0) {
                    printf("%lld\n", pqmn.top());
                    pqmn.pop();
                }
                else{
                    printf("%lld\n", pqmx.top());
                    pqmx.pop();
                }
                count--;
            }
            else{
                int val = atoi(str);
                if(pqmn.empty()) pqmn.push(val);
                else{
                    if(val>= pqmn.top()) pqmn.push(val);
                    else pqmx.push(val);
                }
                
                if(pqmn.size() - 1 > pqmx.size()){
                    pqmx.push(pqmn.top());
                    pqmn.pop();
                }
                else if(pqmx.size()>pqmn.size()){
                    pqmn.push(pqmx.top());
                    pqmx.pop();
                }
                ++count;
                if(count%2==1) flag =1;
                else flag =0;
            }
    }
}

