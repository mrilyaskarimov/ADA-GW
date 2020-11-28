//
//  main.cpp
//  Problem B (Get a tree)
//
//  Created by Ilyas Karimov on 25.11.20.
//

#include <iostream>
using namespace std;
int c = 0, n, m, v;
int g[101][101], used[101];
void dfs(int v){
    used[v] = 1;
    c++;
    for (int i = 1; i <= n; i++)
        if ((g[v][i] == 1) && (used[i] == 0)) dfs(i);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
