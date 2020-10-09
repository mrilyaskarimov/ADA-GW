//
//  main.cpp
//  Problem C (Roads)
//
//  Created by Ilyas Karimov on 10/8/20.
//

#include <iostream>
#define MAX 10001
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


int main(int argc, const char * argv[]) {
    int n, m, a, b, count = 0;

    scanf("%d %d",&n,&m);
    for(int i=1;i<=n; i++){
        mas[i] = i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        Union(a, b);
    }
    for(int i =1 ;i<=n;i++){
        if(mas[i] == i) count++;
    }
    
    printf("%d", (count-1));
}
