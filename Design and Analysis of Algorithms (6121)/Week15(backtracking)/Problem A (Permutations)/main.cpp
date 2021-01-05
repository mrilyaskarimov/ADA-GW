//
//  main.cpp
//  Problem A (Permutations)
//
//  Created by Ilyas Karimov on 23.12.20.
//

#include <cstdio>
#include <algorithm>
using namespace std;

int m[10];
int i, n;

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++) m[i] = i;
    do
    {
   for (i = 1; i <= n; i++)
        printf("%d ", m[i]);
     printf("\n");
    } while (next_permutation(m + 1, m + n + 1));
    return 0;
}
