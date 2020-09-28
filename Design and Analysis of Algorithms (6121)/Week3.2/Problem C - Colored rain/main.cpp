//
//  main.cpp
//  Problem C - Colored rain
//
//  Created by Ilyas Karimov on 9/27/20.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>g;
int arr[101][101];
int col[101];
int colors[3];
int main(int argc, const char * argv[]) {
    int num;
    scanf("%d", &num);
    memset(arr, 0, sizeof(arr));
    memset(col, 0, num);
    g.resize(num+1);
    for (int i=1; i<=num;i++){
        for (int j=1;j<=num;j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    
    for(int i= 1; i<=num; i++){
        scanf("%d", &col[i]);
    }
    for(int i = 1 ; i<= num; i ++){
        
    }
    return 0;
}
