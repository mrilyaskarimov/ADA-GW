//
//  main.cpp
//  Problem E
//
//  Created by Ilyas Karimov on 9/27/20.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
int arr[101][101];
int temp;
int main(int argc, const char * argv[]) {
    int num, count, one;
    scanf("%d", &num);
    memset(arr, 0, num);
    g.resize(num+1);
    for(int i = 1 ; i <=num; i++){
        scanf("%d", &count);
        for(int j = 1; j <= count; j ++){
            scanf("%d", &one);
            g[i].push_back(one);
        }
    }
    for(int i = 1; i <=num ; i++){
//        for(int j = 1; j <= g[i].size(); j++){
//            printf("%d", g[i].at(j));
//        }
        for (auto it = g[i].begin(); it != g[i].end(); it++)
            arr[i][*it] =1;
        printf("\n");
    }
    for(int i = 1; i <= num; i ++){
        for(int j = 1; j <= num; j ++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
   
}
