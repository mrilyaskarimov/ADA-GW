//
//  main.cpp
//  Problem C (Road)
//
//  Created by Ilyas Karimov on 22.11.20.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
// STL library is not compatible with Xcode
#define MAXV 20001
#define MAXE 100001
using namespace std;

struct Edge
{
    int u, v, dist;
}   e[MAXE];

int mas[MAXV], size[MAXV], res;

void swap(int &x, int &y)
{
    int temp = x; x = y; y = temp;
}

int Repr(int n)
{
    if (n == mas[n]) return n;
    return mas[n] = Repr(mas[n]);
}

int Union(int x,int y)
{
    x = Repr(x); y = Repr(y);
    if(x == y) return 0;

    if (size[x] < size[y]) swap(x,y);
    mas[y] = x;
    size[x] += size[y];
    return 1;
}

int lt(Edge a, Edge b)
{
    return (a.dist < b.dist);
}

int main(void)
{
    //n - nodes, m - edges, p and q - two cities (edges) to be checked.
    int i, n, m, p, q, t;
    bool flag = 0;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        memset(mas, 0, sizeof(mas));
        memset(size, 0, sizeof(size));
        scanf("%d %d %d %d", &n, &m, &p, &q);
        
        for(int j = 0 ; j <n; j++){
            mas[j] = j;
            size[j] = 1;
        }
        for(int j = 0 ; j < m; j++){
            scanf("%d %d %d",&e[j].u,&e[j].v,&e[j].dist);
        }
        sort(e,e+m,lt);
        res = 0;
        
        pair <int, int> p1;
        pair <int, int> p2;
        p1.first = p;
        p2.second = p;
        
        p1.second = q;
        p2.first = q;
        
        for(int k = 0; k < m; k++){
            if (Union(e[k].u,e[k].v)){
                pair<int, int> p3;
                p3.first = e[k].u;
                p3.second = e[k].v;
                if(p3 == p1 ||  p3 == p2) flag = 1;
                res += e[k].dist;
            }
        }
            if(flag) puts("YES");
            else puts("NO");
            flag = 0;
    }
  return 0;
}
