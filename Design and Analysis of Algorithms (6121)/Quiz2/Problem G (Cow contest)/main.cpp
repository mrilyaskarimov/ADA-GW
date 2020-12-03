//
//  main.cpp
//  Problem G (Cow contest)
//
//  Created by Ilyas Karimov on 03.12.20.
//

#include <iostream>
using namespace std;
#define MAX 4501
bool g[MAX][MAX];
int n,m, a, b;

int main(void){
   
    scanf("%d %d", &n, &m);
    for(int i = 0; i<m; i++){
        scanf("%d %d", &a, &b);
        g[a][b] = true;
    }
      
    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    if (g[i][k] && g[k][j]) g[i][j] = true;
    
    for (int i = 1; i <= n; i++){
        int count = 0;
        for (int j = 1; j <= n; j++){
            printf("%d ", g[i][j]);
            if(g[i][j] == 1 ) count++;
        }
        printf(" count is %d", count);
        printf("\n");
        }

}
