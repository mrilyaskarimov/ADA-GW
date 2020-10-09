//
//  main.cpp
//  Problem E (Cut a graph)
//
//  Created by Ilyas Karimov on 10/8/20.
//

#include <iostream>
#define MAX 150001
int mas[MAX];

int Repr(int n)
{
  while (n != mas[n]) n = mas[n];
  return n;
}

void Union(int x, int y)
{
  int x1 = Repr(x), y1 = Repr(y);
  if (x1 == y1) return;
  mas[x1] = y1;
}
bool ask(int x, int y){
    int x1 = Repr(x), y1 = Repr(y);
    if(x1 == y1) return 1;
    else return 0;
}
int main(int argc, const char * argv[]) {
    
    int n,m,k,a,b,c,d, count = 0;
    char str[100];
    scanf("%d %d %d",&n, &m, &k );
    
    for(int i=1;i<=n; i++){
        mas[i] = i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        Union(a, b);
    }
    for(int i=1;i<=k;i++){
        scanf("%s", str);
        if(strcmp(str, "ask")==0){
            scanf("%d %d", &c,&d);
            if(ask(c,d))  puts("YES");
            else puts("NO");
        }
    }
    for(int i =1 ;i<=n;i++){
        if(mas[i] == i) count++;
    }
}
