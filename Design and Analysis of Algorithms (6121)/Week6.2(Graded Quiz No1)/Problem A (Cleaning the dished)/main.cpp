//
//  main.cpp
//  Problem A (Cleaning the dished)
//
//  Created by Ilyas Karimov on 01.01.21.
//

#include <iostream>
#include <stack>
using namespace std;
int a,b;
stack <int> dirty;
stack <int> washed;
stack <int> wiped;

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n );
    for(int i = n; i> 0; i--) dirty.push(i);
    while(scanf("%d %d", &a, &b) == 2){
        if(a == 1){
            for(int i = 1; i <= b; i++){
                washed.push(dirty.top());
                dirty.pop();
            }
        }
        if(a == 2){
            for(int i = 1; i <=b; i++){
                wiped.push(washed.top());
                washed.pop();
            }
        }
    }
    for(int i = n; i> 0; i--){
        printf("%d\n", wiped.top());
        wiped.pop();
    }
}
