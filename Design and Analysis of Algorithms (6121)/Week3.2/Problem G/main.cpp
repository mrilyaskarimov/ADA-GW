//
//  main.cpp
//  Problem G
//
//  Created by Ilyas Karimov on 9/25/20.
//

#include <iostream>

int main() {
    int num, sum = 0;
    scanf("%d",&num);
    int arr[101][101];
    
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(i==j && arr[i]==arr[j] && arr[j][i]==1){
                sum++;
                break;
            }
        }
    }
    if(sum>0) puts("YES");
    else puts("NO");
    
}
