//
//  main.cpp
//  Problem D (23 out of 5)
//
//  Created by Ilyas Karimov on 23.12.20.
//

#include <iostream>
#include <algorithm>

using namespace std;
int found = 0;
int a[5], flag;
int RunSum(int Sum, int index)
{
  if (index == 5)
    if (Sum == 23) return 1; else return 0;

  if (RunSum(Sum+a[index],index+1)) return 1;
  if (RunSum(Sum-a[index],index+1)) return 1;
  if (RunSum(Sum*a[index],index+1)) return 1;
  return 0;
}

int main(int argc, const char * argv[]) {
    while(scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]),a[0]+a[1]+a[2]+a[3]+a[4])
    {
      sort(a,a+5);
      flag = 0;

      do{
          if (flag = RunSum(a[0],1)) break;
      } while(next_permutation(a,a+5));


      if (flag) printf("Possible\n"); else printf("Impossible\n");
      memset(a,0,sizeof(a));
    }

}
