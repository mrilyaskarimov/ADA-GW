//
//  main.cpp
//  Problem C - Colored rain
//
//  Created by Ilyas Karimov on 9/27/20.
//

#include <iostream>


using namespace std;

int arr[101][101];
int col[101];
int main(int argc, const char * argv[]) {
    int num, count = 0;
    memset(arr, 0, sizeof(arr));
    memset(col, 0, sizeof(col));
    scanf("%d", &num);
    for(int i=0; i<num;i++){
        for (int j =0; j <num ; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0;i<num;i++){
        scanf("%d", &col[i]);
    }
    for(int i = 0 ; i< num; i++){
        for(int j=0; j<num ; j++){
            if(arr[i][j]==1 && col[i]!=col[j]){
                count ++;
            }
        }
    }
    printf("%d", count/2);
    return 0;
}
