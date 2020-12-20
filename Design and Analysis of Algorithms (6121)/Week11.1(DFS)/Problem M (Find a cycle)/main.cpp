//
//  main.cpp
//  Problem M (Find a cycle)
//
//  Created by Ilyas Karimov on 11.12.20.
//

#include <iostream>
#include <vector>
#define MAX 51
int g[MAX][MAX], used[MAX];
int n, i, j, flag, m, a, b;
using namespace std;
vector<int>res;
//used[v] = prev;
//    for (int i = 0; i < g[v].size(); i++) +
//    {
//        if (used[g[v][i]] > 0 && !result)
//        {
//            result = true;
//            int ii = v;
//            while (ii != used[g[v][i]])
//            {
//                res.push_back(ii);
//                ii = used[ii];
//            }
//            break;
//        }
//        if (used[g[v][i]] == 0) dfs(g[v][i], v);
//    }
    
void dfs(int v, int prev = -1){
    used[v] = 1;
    for (int i = 1; i <= n; i++){
      if (used[g[v][i]] > 0 && !flag){
              flag = 1;
              int ii = v;
              while (ii != used[g[v][i]])
              {
                  res.push_back(ii);
                  ii = used[ii];
              }
              break;
          }
      else if (used[i] == 0) dfs(i);
      }
    used[v] = 2;
}



    
int main(void){
    scanf("%d %d", &n, &m);
    for (i = 1; i <= m; i++){
        scanf("%d %d", &a, &b);
        g[a][b] = 1;
    }
    
    flag = 0;
    for (i = 1; i <= n; i++)
        if (used[i] == 0)
            dfs(i);
    if(flag){
        puts("YES");
        for(i = res.size()-1 ; i>= 0; i--) printf("%d ", res[i]);
    }
    else puts("NO");
}
