// 100%
//  main.cpp
//  Week1
//
//  Created by Ilyas Karimov on 9/10/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    long long  start, end, res = 0; //10^9..
    scanf("%lld %lld", &start, &end);

    //Maybe finding average? so (5-2+1)*(( 5 + 2 ) / 2)
    res = (end-start+1)*(start + end)/2;
    printf("%lld\n", res);
    return 0;
}
