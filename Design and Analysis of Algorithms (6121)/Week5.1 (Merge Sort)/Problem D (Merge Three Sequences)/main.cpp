//
//  main.cpp
//  Problem D (Merge Three Sequences)
//
//  Created by Ilyas Karimov on 29.10.20.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> a,b,c,res, res2;
int main(int argc, const char * argv[]) {
    int num, num2, num3, k=0,l=0,m=0, j=0, p=0;
    scanf("%d", &num);
    a.resize(num);
    for(int i=0;i<num;i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &num2);
    b.resize(num2);
    for(int i=0;i<num2;i++){
        scanf("%d", &b[i]);
    }
    scanf("%d", &num3);
    c.resize(num3);
    for(int i=0;i<num3;i++){
        scanf("%d", &c[i]);
    }
    res.resize(num+num2);
    for(j=0;k<num && l<num2; j++){
        if(a[k]<=b[l]){
            res[j]=a[k];
            k++;
        }
        else{
            res[j]=b[l];
            l++;
        }
    }
    while(k<num) res[j++] = a[k++];
    while(l<num2) res[j++] = b[l++];
    
    res2.resize(num+num2+num3);
    j=0;
    for(p = 0; m<num3 && j<num + num2; p++){
        if(res[j]<=c[m]){
            res2[p]= res[j];
            j++;
        }
        else{
            res2[p]=c[m];
            m++;
        }
    }
    while(m<num3) res2[p++] = c[m++];
    while(j< num+num2) res2[p++] = res[j++];
    
    for(int i= 0;i<num+num2+num3;i++){
        printf("%d ", res2[i]);
    }
    printf("\n");
}
