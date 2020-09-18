//
//  main.cpp
//  5327
//
//  Created by Ilyas Karimov on 9/17/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <stack>
#include <string>

using namespace std;
char str[4000001];
stack <char> st;
int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    int count = 0, sudden = 0 ;
    for(int i = 0; i< str.size(); i++){
        if(str[i] == '('){
            st.push('(');
            count++;
        }
        if(str[i] == ')') {
            if(!st.empty()){
                st.pop();
                count --;
            }else{
                sudden = 1;
                break;
            }
        }
    }
    
    if(sudden == 1 || !st.empty()) puts("NO");
    else puts("YES");
}
