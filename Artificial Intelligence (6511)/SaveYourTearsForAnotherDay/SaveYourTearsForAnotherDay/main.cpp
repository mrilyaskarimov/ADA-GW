//
//  main.cpp
//  SaveYourTearsForAnotherDay
//
//  Created by Ilyas Karimov on 11.04.22.
//

#include <stdio.h>
#include <string.h>
#define MAX 1010
int arr[MAX];

int main(void)
{
    int i, j, val, r, num;
    scanf("%d", &r);

    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &num);
            if (num)
            {
                arr[i]++;
            }
        }
    }
    for (val = i = 0; i < r; i++)
    {
        if (arr[i] == 1)
        {
            ++val;
        }
    }
    printf("%d\n", val);
}
