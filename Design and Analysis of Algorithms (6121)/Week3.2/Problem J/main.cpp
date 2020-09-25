//
//  main.cpp
//  Problem J
//
//  Created by Ilyas Karimov on 9/25/20.
//

#include <iostream>
#include <string.h>
using namespace std;

int g[101][101];

int main(int argc, const char * argv[]) {
    memset(g, 0, sizeof(g));
    int n, m, a, b,count=0;
    scanf("%d %d ",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        g[a-1][b-1] = 1;
        g[a-1][b-1] = 1;
    }
    for(int i=0;i<n; i++){
        count = 0;
        for(int j=0;j<n;j++){
            if(g[i][j]==1)
                count++;
        }
        printf("%d\n",count);
    }
}
