//
//  main.cpp
//  Problem A (Is it a Heap?)
//
//  Created by Ilyas Karimov on 10/6/20.
//

#include <iostream>

using namespace std;
int arr[2000000001];

int main(int argc, const char * argv[]) {
    memset(arr, 0, sizeof(arr));
    int num;
    scanf("%d", &num);
    for(int i=1;i<=num;i++){
        scanf("%d", &arr[num]);
    }
    for(int i=2; i<=num; i++){
        if(arr[i/2]>arr[i]) {
            puts("NO");
            return 0;
        }
        puts("YES");
        return 0;
    }
}
