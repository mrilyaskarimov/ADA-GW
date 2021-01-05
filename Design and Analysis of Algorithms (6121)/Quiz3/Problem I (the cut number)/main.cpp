//
//  main.cpp
//  Problem I (the cut number)
//
//  Created by Ilyas Karimov on 01.01.21.
//

#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;

int m[100];
int i, n, d, c = 0, p, z;
long long res = -1;
int main()
{
    scanf("%d %d",&d, &n);
    for (i = 0; i < n; i++) scanf("%d", &m[i]);
    sort(m, m + n);
//    puts("\n");
    do{
        res = m[0]%d;
        for (i = 1; i < n; i++){
//            printf("%d", m[i]);
            z = 0;
            p = m[i];
            while(p!=0){
                p /= 10;
                z++;
            }
            res = (res * int(pow(10, z)) + m[i]) % d;
            //            printf("%d\n", res);
        }
//        puts("\n");
    if(res == 0) c++;
    } while (next_permutation(m , m + n));
    printf("%d\n", c);
//    printf("%d",z/n);
    return 0;
}
