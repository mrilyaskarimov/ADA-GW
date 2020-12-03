//
//  main.cpp
//  Problem B (Catalan number)
//
//  Created by Ilyas Karimov on 29.11.20.
//

#include <iostream>
#define MAX 10001
long long cat[MAX];
int n, m, i, j;

int main(int argc, const char * argv[]) {
    cat[0] = 1;
    scanf("%d %d", &n, &m);
    
    for (i = 1; i <= n; i++)
    {
      for (j = 0; j < i; j++)
        cat[i] = (cat[i] + cat[j] * cat[i - j - 1])%m;
    }
    printf("%lld", cat[n]);
}
