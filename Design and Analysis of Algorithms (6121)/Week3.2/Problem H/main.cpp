//
//  main.cpp
//  Problem H MULTIEDGES
//
//  Created by Ilyas Karimov on 9/25/20.
//

#include <iostream>
using namespace std;

int arr[101][101];
int main(int argc, const char * argv[]) {
    int n,m,a,b, flag = 0;
    scanf("%d %d", &n,&m);
    memset(arr,0,n);
    
        for(int j = 1; j <=m ; j++){
            scanf("%d %d", &a,&b);
            arr[a][b]++;
            if(arr[a][b]>1){
                flag = 1;
                break;
            }
        }
    if(flag == 1) puts("YES");
    else puts("NO");
}
