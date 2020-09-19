//
//  main.cpp
//  5060
//
//  Created by Ilyas Karimov on 9/17/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
#include <stack>
#define length 200
using namespace std;;

stack <int> st;
int a = 0, b = 0, val;

int main(int argc, const char * argv[]) {
    char str[length];
    
    while(scanf("%s", str) == 1){
        if(str[0] == '+'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a+b);
        }
        else if(str[0] == '-'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b-a);
        }
        else if(str[0] == '*'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a*b);
        }
        else if(str[0] == '/'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b/a);
        }
        else{
            sscanf(str,"%d",&val);
            st.push(val);
        }
    }
    printf("%d", st.top());
    return 0;
}
