//
//  main.cpp
//  Problem F (Power of Time)
//
//  Created by Ilyas Karimov on 17.10.20.
//

#include <iostream>
#include <queue>

using namespace std;

queue<int> order, ideal;

int main(int argc, const char * argv[]) {
    int num, el, time =0;
    scanf("%d", &num);
    for(int i=1;i<=num;i++){
        scanf("%d", &el);
        order.push(el);
    }
    
    for(int i=1;i<=num;i++){
        scanf("%d", &el);
        ideal.push(el);
    }

    while(!ideal.empty()){
//        printf("%d %d\n",order.front(), order.back());
//        printf("%d %d\n",ideal.front(), ideal.back());
        if(order.front() == ideal.front()){
            order.pop();
            ideal.pop();
        }
        else{
            int temp = order.front();
            order.pop();
            order.push(temp);
        }
        time++;

    }
    printf("%d", time);
}
