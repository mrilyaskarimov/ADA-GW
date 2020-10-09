//
//  main.cpp
//  Problem C (Merge the sequence)
//
//  Created by Ilyas Karimov on 10/7/20.
//


#include <iostream>
#include <vector>
using namespace std;

vector <int> a, b, res;

int main(int argc, const char * argv[]) {
    int j = 0, num, num2, p=0,  q=0;
    scanf("%d", &num);
    a.resize(num);
    for(int i=0;i<num;i++){
        scanf("%d", &a[i] );
    }
    scanf("%d", &num2);
    b.resize(num2);
    for(int i=0;i<num2;i++){
        scanf("%d", &b[i]);
        
    }
    res.resize(num+num2);
    for(j=0; p<num && q<num2; j++ ){
        if(a[p]<=b[q]) {
            res[j] = a[p];
            p++;
        }
        else{
            res[j]=b[q];
            q++;
        }
    }
    
    while (p < num)  res[j++] = a[p++];
    while (q < num2) res[j++] = b[q++];

    for (int i = 0; i < num + num2; i++)
        printf("%d ", res[i]);
        printf("\n");
   return 0;
    
}
