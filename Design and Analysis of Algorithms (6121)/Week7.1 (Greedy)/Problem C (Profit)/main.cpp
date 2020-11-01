//
//  main.cpp
//  Problem C (Profit)
//
//  Created by Ilyas Karimov on 28.10.20.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,val, s = 0, max = 0;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%d", &val);
        s+= val;
        if(s > max) max =s;
        if(s<0) s=0;
    }
    printf("%d\n",max);
}
