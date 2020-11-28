//
//  main.cpp
//  Problem G (Decomposition of three digit)
//
//  Created by Ilyas Karimov on 26.11.20.
//

#include <iostream>

int expo(int &x){ //callee - the function itself, x - formal parameter
    return x = x*x; // return should be int type, returning x*x.
}
int main() {
    int n; //actual parameter
    scanf("%d", &n); //scanning from console
    printf("%d %d\n", expo(n), n);
    /* expo(n) is caller. printing expo(n) result and also actual parameter, to show you actually n is not affected. */
}
