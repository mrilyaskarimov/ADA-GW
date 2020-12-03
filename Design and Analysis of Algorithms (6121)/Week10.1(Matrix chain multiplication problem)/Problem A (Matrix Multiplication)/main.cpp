//
//  main.cpp
//  Problem A (Matrix Multiplication)
//
//  Created by Ilyas Karimov on 29.11.20.
//

#include <iostream>
#define SIZE 101
using namespace std;
int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE];
int i, j, k, na, nb, ma, mb;

int main(int argc, const char * argv[]) {
    scanf("%d %d", &na, &ma);
    for (i = 0; i< na; i++)
        for(j = 0; j<ma; j++)
        scanf("%d", &a[i][j]);
    scanf("%d %d", &nb, &mb);
    for (i = 0; i< nb; i++)
        for(j = 0; j<mb; j++)
        scanf("%d", &b[i][j]);
    
    if(nb==ma){
        for (i = 0; i < na; i++)
        for (j = 0; j < mb; j++)
        for (k = 0; k < ma; k++)
            c[i][j] += a[i][k] * b[k][j];
        
        printf("%d %d\n", na, mb);
        for(i = 0; i < na; i++){
            for(j = 0; j < mb; j++) printf("%d ", c[i][j]);
            printf("\n");
        }
    }
    else printf("%d", -1);

}
