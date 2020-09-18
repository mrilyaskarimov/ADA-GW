//
//  main.cpp
//  6122
//
//  Created by Ilyas Karimov on 9/17/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
#include <stack>
#include <stdio.h>
#include <cstring>


using namespace std;
char s[100];
int num;
stack <int> st;
int main(int argc, const char * argv[]) {

    while(scanf("%s", s) == 1){
        if(strcmp(s, "push") == 0) {
            scanf("%d", &num);
            st.push(num);
            puts("ok");
        }
        if(strcmp(s, "size") == 0){
            cout << st.size() << endl;
        }
        if(strcmp(s, "pop") == 0) {
            printf("%d\n", st.top());
            st.pop();
        }
        if(strcmp(s, "clear") == 0) {
            while(!st.empty()) st.pop();
            puts("ok");
        }
        if(strcmp(s, "back") ==0){
            printf("%d\n",st.top());
        }
        if(strcmp(s, "exit") == 0){
            puts("bye");
            return 0;
        }
    }
    
}
