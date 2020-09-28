//
//  main.cpp
//  Problem L - Regular graph
//
//  Created by Ilyas Karimov on 9/27/20.
//Graph is regular if for any vertice, the degree of the vertice is the same. her bir vertice den eyni qeder edge cixirsa! 

#include <iostream>

using namespace std;

int deg[101];
int main(int argc, const char * argv[]) {
    int n,m,a,b;
    scanf("%d %d", &n,&m);
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= m; i++){
        scanf("%d %d",&a,&b);
        deg[a]++;
        deg[b]++;
    }
    int same = 0;
    for(int i = 1; i < n; i++){
        if(deg[i+1] != deg[i])
            same = 1;
    }
    if (same!=0) puts("NO");
    else puts("YES");
    return 0;
}
