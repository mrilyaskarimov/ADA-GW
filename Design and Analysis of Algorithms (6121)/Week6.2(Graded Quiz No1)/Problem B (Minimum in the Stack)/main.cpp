//
//  main.cpp
//  Problem B (Minimum in the Stack)
//
//  Created by Ilyas Karimov on 04.11.20.
//

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<long long>s;
int main(int argc, const char * argv[]) {
    int num;
    long long op,el ;
    scanf("%d", &num);
    for(int i=0;i<num;i++){
        scanf("%lld", &op);
        if(op==1){
            scanf("%lld", &el);
            if(s.empty()) s.push(el);
            else s.push(min(s.top(), el));
        }
        if(op==2) s.pop();
        if(op==3) printf("%lld\n",s.top());
    }
}
