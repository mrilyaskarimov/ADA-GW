//
//  main.cpp
//  Problem E (Divisibility)
//
//  Created by Ilyas Karimov on 26.11.20.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    
    if(n%m==0) puts("Divisible");
    else printf("%d %d", n/m, n%m);
}
