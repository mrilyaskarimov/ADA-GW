//
//  main.cpp
//  Problem I - Degree of vertices
//
//  Created by Ilyas Karimov on 9/27/20.
//

#include <iostream>

using namespace std;
int arr[101][101];

int main(int argc, const char * argv[]) {
    int num, count = 0;
    scanf("%d", &num);
    memset(arr,0,num);
    for(int i=1; i<=num; i++){
        for(int j=1; j<=num;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=1; i <=num ; i++){
        count =0;
        for(int j=1; j <=num ;j++){
            if(arr[i][j] ==1) count++;
        }
        printf("%d\n", count);
    }
}
