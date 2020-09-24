//
//  main.cpp
//  10143
//
//  Created by Ilyas Karimov on 9/17/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

deque <int> deq [150001];
char str[500];
int a,b;
int main(int argc, const char * argv[]) {
    int num;
    scanf("%d", &num);
    for (int i=0; i<num; i++){
        scanf("%s", str);
        if(strcmp("pushback", str) ==0){
            scanf("%d %d", &a, &b);
            deq[a].push_back(b);
        }
        if(strcmp("pushfront", str) ==0){
            scanf("%d %d", &a, &b);
            deq[a].push_front(b);
        }
        if(strcmp("popfront", str) ==0){
            scanf("%d", &a);
            printf("%d\n", deq[a].front());
            deq[a].pop_front();
        }
        if(strcmp("popback", str) ==0){
            scanf("%d", &a);
            printf("%d\n", deq[a].back());
            deq[a].pop_back();
        }
    }
}
