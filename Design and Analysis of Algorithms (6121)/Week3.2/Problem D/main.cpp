//
//  main.cpp
//  Problem D
//
//  Created by Ilyas Karimov on 9/25/20.
//

#include <cstdio>
#include <vector>
using namespace std;

int i, j, n, val;
vector<vector<int> > g;

int main(int argc, const char * argv[]) {

    scanf("%d",&n);
      g.resize(n+1);
      for(i = 1; i <= n; i++)
      for(j = 1; j <= n; j++)
      {
        scanf("%d",&val);
        if (val==1) g[i].push_back(j);
      }

      for(i = 1; i <= n; i++)
      {
        printf("%d",g[i].size());
        for(j = 0; j < g[i].size(); j++)
          printf(" %d",g[i][j]);
        printf("\n");
      }
      return 0;
}
