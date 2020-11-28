#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define SIZE 1002

using namespace std;
int arr1[SIZE], arr2[SIZE], arr3[SIZE],mas[2][SIZE][SIZE], dp[SIZE][SIZE][SIZE];
int n, m,l,  i, j, k;

int f(int i, int j, int k) {
    if (i<=0 || j<=0 || k<=0) return 0;
    
    if (dp[i][j][k] == -1) {
    if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) return dp[i][j][k] = 1 +  f(i-1,j-1,k-1);
    else return dp[i][j][k] = max(max(f(i-1, j, k), f(i, j-1, k)), f(i,j,k-1));
    }
    else return dp[i][j][k];

}
int main(void)
{

    scanf("%d",&n);
    for(i = 1; i <= n; i++) scanf("%d",&arr1[i]);
    scanf("%d",&m);
    for(i = 1; i <= m; i++) scanf("%d",&arr2[i]);
    scanf("%d",&l);
    for(i = 1; i <= l; i++) scanf("%d",&arr3[i]);
 
    memset(mas,0,sizeof(mas));
    memset(dp,-1,sizeof(dp));


    printf("%d\n", f(n,m,l));
//    for(i = 1; i <= n; i++){
//        for(j = 1; j <= m; j++){
//            for(k = 1; k <= l; k++){
//                printf("%d ", dp[i][j][l]);
//            }
//            printf("\n");
//        }
//        printf("\n");
//    }
  return 0;
}
