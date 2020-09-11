// 91%
//  main.cpp
//  8669
//
//  Created by Ilyas Karimov on 9/10/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    unsigned int dividend;
    scanf("%d", &dividend);
    for (unsigned int i=1; i*i<=dividend; i++){
        if (dividend % i == 0){
            printf("%d ",i);
        }
        if(dividend/i != i){
            printf("%d ", i);
        }
        else{
            
        }
  
        
    }
    printf("%d ", dividend);
}
