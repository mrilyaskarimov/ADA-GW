//
//  main.cpp
//  Problem B (Bridges)
//
//  Created by Ilyas Karimov on 06.01.21.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;
int n, el;
int tm[MAX];

int mx(int a, int b){
    return (b>a)?b:a;
}
int mn(int a, int b){
    return (a>b)?b:a;
}
int GreedySearch(int n, int tm[], int flag){ // flag is for
    if(n == 1){
        if(flag == 1) printf("%d\n", tm[0]); // when it's one person, should only print the speed of him
        return tm[0]; //returning the only person's overall time
    }
    if(n == 2){
        if(flag == 1) printf("%d %d\n", tm[0], tm[1]); //
        return mx(tm[0], tm[1]); // total time is max
    }
    if(n == 3){
        if(flag == 1) {
            printf("%d %d\n", tm[0], tm[1]); // first two go
            printf("%d\n", tm[0]); // first comes back
            printf("%d %d\n", tm[0], tm[2]); // first and last goes
        }
        return tm[0] + tm[1] + tm[2];
    }
    int case1 =  tm[0] + 2*tm[1] + tm[n-1];
    int case2 =  2*tm[0] +tm[n-2] + tm[n-1];
  
    int strategy = mn(case1, case2);
    if(flag == 1){
        if(strategy == case1){
            printf("%d %d\n", tm[0], tm[1]);//AB go
            printf("%d\n", tm[0]);// A comes
            printf("%d %d\n", tm[n-2], tm[n-1]);// YZ go
            printf("%d\n",tm[1]);// B comes
        }
        else{
            printf("%d %d\n", tm[0], tm[n-1]);//AZ go
            printf("%d\n", tm[0]);//A comes
            printf("%d %d\n",tm[0], tm[n-2]);//AY go
            printf("%d\n", tm[0]);//A come
        }
    }
        
    return strategy + GreedySearch(n-2, tm, flag);

}
int main(int argc, const char * argv[]) {
    while(scanf("%d", &n) == 1){ // people
        int total, flag = 0;
        for(int i = 0; i<n; i++) scanf("%d", &tm[i]); // time
        sort(tm, tm+n);
        
        total = GreedySearch(n, tm, flag);
        printf("%d\n",total);
        //now every move
        flag = 1;
        GreedySearch(n, tm, flag);
    }
}
