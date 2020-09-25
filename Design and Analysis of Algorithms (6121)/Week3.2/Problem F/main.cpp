//
//  main.cpp
//  Problem F
//
//  Created by Ilyas Karimov on 9/25/20.
//

#include <iostream>
#include <vector>
#define MAX 101

using namespace std;
vector<vector<int>> g;
int arr[MAX][MAX];

int main(int argc, const char * argv[]) {
    int n, m, a,b;
    scanf("%d %d", &n,&m);
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        arr[a-1][b-1] = 1;
        arr[b-1][a-1] = 1;
    }
    for( int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           printf("%d ",arr[i][j]);
       }
    printf("\n");
    }
}
