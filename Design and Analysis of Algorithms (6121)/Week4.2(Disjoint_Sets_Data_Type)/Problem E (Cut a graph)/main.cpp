//
//  main.cpp
//  Problem E (Cut a graph)
//
//  Created by Ilyas Karimov on 10/8/20.


/*
 NOTE from Ilyas: I dont understand why we are scanning a and b tho? we dont use them.
    Instead, we did the reverse order.
    I listened to lecture recording 4 times, but I feel like this is not the right algorithm(the way I did).
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 150001

using namespace std;

vector<int> parent, depth;
vector <string> answers;

int arr[MAX][3];

int Repr(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = Repr(parent[v]);
}

void Union(int x, int y)
{
    x = Repr(x); y = Repr(y);
    if (x == y) return;
    if (depth[x] < depth[y]) parent[x] = y;
    else parent[y] = x;
    if (depth[x] == depth[y]) depth[x]++;
}

int main(int argc, const char * argv[]) {
    
    int n,m,k;
    scanf("%d %d %d",&n, &m, &k );
    
    parent.resize(n+1);
    depth.resize(n+1);

    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        depth[i] = 0;
    }

    int b, c;
    while(m--)
        scanf("%d %d", &b, &c);

    string command;
    for(int i = 1;i <= k; i++){
        
        cin >> command >> b >> c;
        if(command == "cut") arr[i][0] = 1;
        else arr[i][0] = 0;
        arr[i][1] = b;
        arr[i][2] = c;
    }
    for (int i = k; i > 0; i--){
        if(arr[i][0] == 0)
            answers.push_back((Repr(arr[i][1]) == Repr(arr[i][2])) ? "YES" : "NO");
        else
            Union(arr[i][1],arr[i][2]);
    }
   while(!answers.empty())
   {
       cout << answers.back() << endl;
       answers.pop_back();
   }
}
