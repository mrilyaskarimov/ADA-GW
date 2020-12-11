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
int n,m, a, u, num = 0;

int main(void){
   
    scanf("%d %d", &n, &m);
    for(int i = 0; i<m; i++){
        scanf("%d %d", &a, &u);
        g[a][u] = true;
    }
      
    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    if (g[i][k] && g[k][j]) g[i][j] = true;
    
    for (int i = 1; i <= n; i++){
        int count = 0;
        for (int j = 1; j <= n; j++){
//            printf("%d ", g[i][j]);
            if(g[i][j] == 1 || g[j][i] == 1) count++;
           
        }
        if(count == n - 1) num++;
//        printf(" count is %d", num);
//        printf("\n");
        }
    printf("%d", num);

}
