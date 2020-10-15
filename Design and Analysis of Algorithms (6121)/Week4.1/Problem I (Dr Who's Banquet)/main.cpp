//
//  main.cpp
//  Problem I (Dr Who's Banquet)
//
//  Created by Ilyas Karimov on 10/11/20.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> pq;
int num; char c;

bool chat(priority_queue<int> pq){
    
    while(!pq.empty()){
        
        int temp = pq.top();
        pq.pop();
        queue<int>new_q;
        while(temp--){
            if(pq.empty()) return false;
            if(pq.top()!=1) new_q.push(pq.top()-1);
            pq.pop();
        }
        while(!new_q.empty()){
            pq.push(new_q.front());
            new_q.pop();
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    while(scanf("%d%c", &num, &c)==2){
        pq.push(num);
        if(c == '\n'){
            printf(chat(pq) ? "ok\n\n" : "fail\n\n");
           
            while(!pq.empty()){
                pq.pop();
            }
        }
    }
}
