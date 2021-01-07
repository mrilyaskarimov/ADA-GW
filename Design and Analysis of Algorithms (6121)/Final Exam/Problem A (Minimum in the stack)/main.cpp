//
//  main.cpp
//  Problem A (Minimum in the stack)
//
//  Created by Ilyas Karimov on 06.01.21.
//

#include <iostream>
#include <deque>

using namespace std;
long long n, res = 0;
int a,b,c, x;
deque<int> deq, mind;
int main(int argc, const char * argv[]) {
    scanf("%lld %d %d %d %d", &n, &a, &b,&c, &x);
    for(int i = 0; i < n; i++){
        x = (((1LL*a*x*x + 1LL*b*x + c) / 100 ) % 1000000LL);
        if(x%5 < 2){
            if(!deq.empty()){
                if(deq.front() == mind.front()) mind.pop_front();
                deq.pop_front();
            }
        }
        else{
            deq.push_back(x);
            while(!mind.empty() && (x < mind.back())) mind.pop_back();
            mind.push_back(x);
        }
        if(!mind.empty()) res += mind.front();
    }
    printf("%lld", res);
}
