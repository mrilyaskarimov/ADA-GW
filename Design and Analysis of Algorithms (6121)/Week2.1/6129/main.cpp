//
//  main.cpp
//  6129
//
//  Created by Ilyas Karimov on 9/17/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
#include <deque>
#include <cstring>

#define MAX 100
using namespace std;

deque <int> deq;
char str[MAX];
int num;

int main(int argc, const char * argv[]) {
    while(scanf("%s", str) == 1){
        if(strcmp(str, "push_back")==0){
                    scanf("%d", &num);
                    deq.push_back(num);
                    puts("ok");
        }
        if(strcmp(str, "push_front")==0){
            scanf("%d", &num);
            deq.push_front(num);
            puts("ok");
        }
        if(strcmp(str, "size") ==0){
            printf("%d\n", deq.size());
        }
        if(strcmp(str, "clear")==0){
            deq.clear();
            puts("ok");
        }
        
        if(strcmp(str, "exit")==0){
            puts("bye");
            return 0;
        }
        if(!deq.empty()){
            if(strcmp(str, "pop_back")==0){
                printf("%d\n", deq.back());
                deq.pop_back();
            }
            if(strcmp(str, "pop_front")==0){
                printf("%d\n", deq.front());
                deq.pop_front();
            }
            if(strcmp(str, "back")==0){
                printf("%d\n", deq.back());
            }
            if(strcmp(str, "front")==0){
                printf("%d\n", deq.front());
            }
        }
        else{
            if(strcmp(str, "clear")!=0 && strcmp(str, "size")!=0){
                puts("error");
            }
          
        }
            
    }
}
