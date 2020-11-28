//
//  main.cpp
//  Problem F (Dibivibility by numbers)
//
//  Created by Ilyas Karimov on 26.11.20.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n,m,l;
    scanf("%d %d %d", &n, &m, &l);
    if(n%m==0 && n%l==0) puts("YES");
    else puts("NO");
}
