//
//  main.cpp
//  Problem H (Train Swapping)
//
//  Created by Ilyas Karimov on 30.10.20.
//

#include <iostream>
#define MAX 10001

using namespace std;
int m[MAX];
int main(int argc, const char * argv[]) {
    int n, num, res=0;;
    scanf("%d", &n);
    for(int k=0;k<n;k++){
        scanf("%d", &num);
        for(int p=0;p<num;p++){
            scanf("%d", &m[p]);
        }
        res=0;
        for(int i=0;i<num-1;i++)
        for(int j=i+1;j<num;j++){
            if(m[i]>m[j]) res++;
        }
        printf("Optimal train swapping takes %d swaps.\n", res);
    }
    return 0;
}
