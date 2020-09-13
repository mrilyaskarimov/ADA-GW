// 91%
//  main.cpp
//  8669
//
//  Created by Ilyas Karimov on 9/10/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> divs;

int main(int argc, const char * argv[]) {
    int dividend;
    scanf("%d", &dividend);
    for (int i = 1; i*i <= dividend; i++){
        if (dividend%i==0){
            if (dividend/i!=i){
//                printf("%d %d\n", i, dividend/i);
                divs.push_back(i);
                divs.push_back(dividend/i);
            }
            else{
//                printf("%d\n", i);
                divs.push_back(i);
                
            }
       }
    }
    sort(divs.begin(), divs.end());
    
    for (auto x : divs)
           printf("%d ",x);
}

