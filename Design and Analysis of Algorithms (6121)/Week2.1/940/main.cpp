//
//  main.cpp
//  940
//
//  Created by Ilyas Karimov on 9/17/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;
stack <int> st;


int main(int argc, const char * argv[]) {
    int count, c = 0, cnt = 0;
    scanf("%d", &count);
    int a[count];
    for (int i = 0; i < count; i++){
        scanf("%d", &a[i]);
        if(st.empty())  {
            st.push(a[i]);
            c++;
        }
        else{
            if(a[i] == st.top())  {
                st.push(a[i]);
                c++;
            }else {
                st.pop();
                c--;
            }
            
        }
    }
    if(c != 0){
        for (int i = 0; i<count; i++){
            if (st.top() == a[i]){
                cnt++;
            }
        }
    }
    if(!st.empty() && cnt > count/2) printf("%d", st.top());
    else printf("%d", -1);
}
