//
//  main.cpp
//  Problem P (Knapsack)
//
//  Created by Ilyas Karimov on 11.11.20.
//

#include <iostream>
#define MAX 10001
    
int main(int argc, const char * argv[]) {
    int m[MAX];
    int s, w, i;
    scanf("%d",&s);
        memset(m,0,sizeof(m));
        m[0] = 1;
    while(scanf("%d",&w) == 1){
      for(i = s; i >= w; i--)
        if (m[i - w] == 1) m[i] = 1;
    }
    for(i = s;; i--)
      if (m[i] > 0) break;
    printf("%d\n",i);
}
