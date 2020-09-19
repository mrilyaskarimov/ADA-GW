//
//  main.cpp
//  8355
//
//  Created by Ilyas Karimov on 9/17/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;
deque<int> deq;

int main(int argc, const char * argv[]) {
    int count, num, num2;
    scanf("%d", &count);
    for(int i=0; i<count; i++){
        scanf("%d", &num);
        if(num == 1 || num == 2){
            scanf("%d", &num2);
            if(num == 1){
                deq.push_back(num2);
            }
            else{
                deq.push_front(num2);
            }
        }
        if(num == 3 || num == 4){
            if(num == 3){
                printf("%d\n", deq.back());
                deq.pop_back();
            }
            else{
                printf("%d\n", deq.front());
                deq.pop_front();
            }
        }
    }
}
