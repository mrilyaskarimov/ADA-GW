//
//  main.cpp
//  Problem E (The Settlers of Catan)
//
//  Created by Ilyas Karimov on 23.12.20.
//

#include <iostream>
#define MAX 26
using namespace std;
int i, best, n, m, a, b; 
int mas[MAX][MAX];

void run(int i, int depth){
    if (depth > best) best = depth;
    for (int j = 0; j < n; j++)
        if (mas[i][j]){
        mas[i][j] = mas[j][i] = 0;
        run(j, depth + 1);
        mas[i][j] = mas[j][i] = 1;
    }
}

int main(int argc, const char * argv[]) {
    while (scanf("%d %d", &n, &m), n + m){
      memset(mas, 0, sizeof(mas));

      for (i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        mas[a][b] = mas[b][a] = 1;
      }
      best = 0;
      for (i = 0; i < n; i++)
        run(i, 0);
      printf("%d\n", best);
    }

}
