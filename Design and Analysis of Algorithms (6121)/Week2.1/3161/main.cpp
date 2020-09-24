//
//  main.cpp
//  3161
//
//  Created by Ilyas Karimov on 9/17/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

deque<int> remaining;
deque<int> discarded;

int main(int argc, const char * argv[]) {
    int num;
    while(scanf("%d", &num)==1){
        for(int i=1;i<=num;i++){
            remaining.push_back(i);
        }
        if(num == 0) return 0;
        while(remaining.size() >= 2){
            discarded.push_back(remaining.front());
            remaining.pop_front();
            remaining.push_back(remaining.front());
            remaining.pop_front();
        }
        
        printf("Discarded cards:");
        while(discarded.size()>1){
            printf(" %d,",discarded.front());
            discarded.pop_front();
        }
        printf(" %d\n", discarded.front());
        printf("Remaining card: %d\n", remaining.back());
        discarded.clear();
        remaining.clear();
    }
    
}
