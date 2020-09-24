//
//  main.cpp
//  HackerEarthProblemDoubleEndQueue
//
//  Created by Ilyas Karimov on 9/24/20.
//

#include <iostream>
#include <deque>

using namespace std;
deque<int> deq;
char str[200];

int main(int argc, const char * argv[]) {
    int num, deq_size, el1, el2;

    scanf("%d", &deq_size);
    scanf("%d", &num);
    for(int i = 1; i<=num; i++){
        scanf("%d", &el1);
        if(el1 == 1){
            scanf("%d", &el2);
            if(deq.size()!= deq_size){
                deq.push_front(el2);
            }
            else{
                puts("Queue overflow");
            }
        }
        else if(el1==2){
            scanf("%d", &el2);
            if(deq.size()!= deq_size){
                deq.push_back(el2);
            }
            else{
                puts("Queue overflow");
            }
        }
        else if(el1 == 3){
            if(!deq.empty()){
                deq.pop_front();
            }
            else{
                puts("Queue underflow");
            }
        }
        else if(el1 == 4){
            if(!deq.empty()){
                deq.pop_back();
            }
            else{
                puts("Queue underflow");
            }
        }
    }
    for(int i=0 ; i <= deq.size();i++){
        printf("%d ", deq.back());
        deq.pop_back();
    }
}
