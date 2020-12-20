//
//  main.cpp
//  Problem N (Dwarves)
//
//  Created by Ilyas Karimov on 12.12.20.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#define MAX 100001

using namespace std;
vector<vector<int> > g;
vector<int> used;
map<string, int> m;
bool flag;
int n = 0, stat, i;
char ch, s1[10000], s2[10000];

void dfs(int v)
{
    if (flag == 1) return;
    used[v] = 1;
    for (int c  = 1; c <= stat; c++){
        if (used[c] == 1) {
            flag = true;
            return;
        }
        if (used[c] == 0) dfs(c);
    }
    used[v] = 2;
}

int main(int argc, const char * argv[]) {

 
    scanf("%d", &stat);
    g.resize(10001);
    used.resize(10001, 0);
   
    n = 0;
    for (i = 0; i < stat; i++){
    // read relation s1 < s2 or s1 > s2
        scanf("%s %c %s", s1, &ch, s2);
        // m[s] contains the vertex number for dwarf s
        // if m[s1] yet is not set up, assign vertex number ++n to dwarf s1
        if (m[s1] == 0) m[s1] = ++n;
        if (m[s2] == 0) m[s2] = ++n;
        // s1 < s2 for dwarves means m[s1] -> m[s2]
        // there is a directed edge from m[s1] to m[s2]
        int from = m[s1], to = m[s2];
        if (ch == '<')
            g[from].push_back(to); // from -> to
        else
            g[to].push_back(from); // to ->from
    }
    flag = 0; // no cycle initially
    for (i = 1; i <= n; i++){
        if (used[i] == 0) dfs(i);
        if (flag == 1) break;
    }
    if(flag==1) puts("impossible\n");
    else puts("possible\n");
    
}

