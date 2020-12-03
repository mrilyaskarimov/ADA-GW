#include <stdio.h>
#include <iostream>
#define MAX 1001
using namespace std;
int x[MAX], lis[MAX], n, i, pos, len, L[MAX];

int main(){
    scanf("%d",&n);
    memset(L, 0, sizeof(L));
    while(scanf("%d",&n)==1){
        for(i = 0; i < n; i++)
        scanf("%d",&x[i]);
        for (len = i = 0; i < n; i++)
            {
              pos = lower_bound(lis,lis+len,x[i]) - lis;
              lis[pos] = x[i];
              L[i] = pos;
              if (pos == len) len++;
        }
        printf("%d\n",len);
    }

}
