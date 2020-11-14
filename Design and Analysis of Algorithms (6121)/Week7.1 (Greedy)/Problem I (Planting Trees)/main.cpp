//
//  main.cpp
//  Problem I (Planting Trees)
//
//  Created by Ilyas Karimov on 04.11.20.
//

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
int f(int a, int b){
    return a>b;
}
int main(int argc, const char * argv[]) {
    int num, d[MAX], t=2, max = -5;
    scanf("%d", &num);
    for(int i=0;i<num;i++) scanf("%d", &d[i]);
    sort(d, d + num, f);
    for(int i=0;i<num;i++){
        d[i]+=i+t;
        if(d[i]>max) max=d[i];
    }
    printf("%d", max);
}
