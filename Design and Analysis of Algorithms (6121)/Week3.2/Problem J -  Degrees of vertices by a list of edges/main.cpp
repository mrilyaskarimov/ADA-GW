//
//  main.cpp
//  Problem J -  Degrees of vertices by a list of edges
//
//  Created by Ilyas Karimov on 9/27/20.
//

#include <iostream>
#include <vector>
using namespace std;
int arr[101][101];
int main(int argc, const char * argv[]) {
    int n,m,a,b, count=0;
    scanf("%d %d",&n,&m);
    memset(arr,0,n);
    for(int i = 1; i<=m; i++){
        scanf("%d %d", &a,&b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for(int i=1;i<=n;i++){
        count=0;
        for(int j =1; j<=n ; j++){
            if(arr[i][j]==1) count++;
        }
        printf("%d\n", count);
    }
}
