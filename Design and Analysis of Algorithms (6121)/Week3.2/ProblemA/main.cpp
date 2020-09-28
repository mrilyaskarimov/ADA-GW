//  main.cpp
//  Cities and roads
//
//  Created by Ilyas Karimov on 9/25/20.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int num, count = 0;
    scanf("%d", &num);
    int arr[num][num];
    for (int i = 0; i < num; i++){
        for(int j=0;j < num; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i = 0; i < num; i++){
        for(int j=0;j < num; j++){
            if(arr[i][j]==arr[j][i] && arr[i][j] == 1){
                count++;
            }
        }
    }
    printf("%d", count/2);
}
