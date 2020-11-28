//
//  main.cpp
//  Problem B (Removing the letters)
//
//  Created by Ilyas Karimov on 24.11.20.
//
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
#define SIZE 1002
using namespace std;

char s1[SIZE], s2[SIZE];
int arr1[SIZE], arr2[SIZE], mas[2][SIZE];
int i, j;

int max(int i,int j)
{
  return (i > j) ? i : j;
}
int main(void){
    
    while(scanf("%s %s", s1+1, s2+1)==2){
        memset(mas,0,sizeof(mas));
        
        int lens1 = strlen(s1+1);
        int lens2 = strlen(s2+1);
        
        for(i = 1; i <= lens1; i++)
            for(j = 1; j <= lens2; j++)
                if (s1[i]==s2[j]) mas[i%2][j] = 1 + mas[(i+1)%2][j-1];
                else mas[i%2][j] = max(mas[(i+1)%2][j],mas[i%2][j-1]);
        printf("%d\n",mas[lens1%2][lens2]);
    }
    return 0;
}
