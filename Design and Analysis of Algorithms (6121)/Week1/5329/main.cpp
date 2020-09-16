//
//  main.cpp
//  5329
//
//  Created by Ilyas Karimov on 9/10/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//PARTY

#include <iostream>
int party [501][501];

int Cnk (int n, int k){
    if (k==n || k==0) return 1;
    if (party[n][k] != -1 ) return party[n][k];
    return party[n][k] = ((Cnk(n-1, k - 1) + Cnk(n-1, k)))%9929;
    
}
int main(int argc, const char * argv[]) {
    int n,k;
    scanf("%d %d", &n,&k);
    memset(party, -1, sizeof(party));
    printf("%d", (Cnk(n, k)));
}
