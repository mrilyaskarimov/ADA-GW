//
//  main.cpp
//  940
//
//  Created by Ilyas Karimov on 9/17/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
// 62% verir, 92% vereni de var idi

#include <iostream>
#include <stack>

using namespace std;
stack <int> st;
stack <int> st2;
int main(int argc, const char * argv[]) {
    int count, num, c = 0, maj=0;
    scanf("%d", &count);
    for (int i = 1; i <=count; i++){
        scanf("%d", &num);
        st2.push(num);
        if(st.empty())  {
            st.push(num);
        }
        else{
            if(num == st.top())  {
                st.push(num);
            }else {
                st.pop();
            }
        }
        
    }
    if(!st.empty()) {
        maj = st.top();
        for(int i = 1; i<=count; i++){
            if(maj == st2.top()) {
                c++;
            }
            st2.pop();
        }
        if(c> num/2) printf("%d", st.top());
        else printf("%d", -1);
    }
    else printf("%d", -1);
}
