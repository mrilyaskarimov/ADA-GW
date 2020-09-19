//
//  main.cpp
//  5087
//
//  Created by Ilyas Karimov on 9/17/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;
stack <int> st;

int main(int argc, const char * argv[]) {
    int count, num, num2, maj ;
    scanf("%d", &count);
    int a[count];
    
    for (int i = 1; i <= count; i++){
        scanf("%d", &a[i]);
        if(a[i] == 1){
            scanf("%d", &num2);
            st.push(num2);
        }
        else {
            printf("%d\n", st.top());
            st.pop();
        }
    }
}
