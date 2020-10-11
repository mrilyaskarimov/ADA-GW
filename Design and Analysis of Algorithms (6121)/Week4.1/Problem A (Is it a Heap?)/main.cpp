//
//  main.cpp
//  Problem A (Is it a Heap?)
//
//  Created by Ilyas Karimov on 10/6/20.
//

#include <iostream>

using namespace std;
int arr[2000001];

int main(int argc, const char * argv[]) {
    memset(arr, 0, sizeof(arr));
    int num, count = 0;
    scanf("%d", &num);
    for(int i=1;i<=num;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=2; i<=num; i++){
        if(arr[i/2]>arr[i]) {
            count++;
        }
    }
    if(count == 0 ) puts ("YES");
    else  puts("NO");
 
}
