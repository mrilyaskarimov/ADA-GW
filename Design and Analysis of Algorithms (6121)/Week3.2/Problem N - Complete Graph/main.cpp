//
//  main.cpp
//  Problem N - Complete Graph
//
//  Created by Ilyas Karimov on 9/27/20.
// GRAPH IS COMPETE IF arr[i][j] is equal to 1 for any i!=j! diaqonalda 1 olmamalidi ve diaqonaldan bawqqa hamsi 1 olmalidi! 

#include <iostream>
int arr[101][101];
int main(int argc, const char * argv[]) {
    int n,m, a,b;
    scanf("%d %d", &n,&m);
    memset(arr,0,n);
    for(int i = 1; i <=m; i++){
        scanf("%d %d", &a,&b);
        arr[a][b]= 1;
        arr[b][a]= 1;
    }
    int same = 0;
    for(int i = 1; i<= n ; i++){
        for( int j = 1 ; j <=n ; j++){
            if( i == j){
                if(arr[i][j] == 1) same = 1;
            }
            else{
                if(arr[i][j] == 0) same = 1;
            }
        }
    }
    if(same == 1) puts("NO");
    else puts("YES");
}
