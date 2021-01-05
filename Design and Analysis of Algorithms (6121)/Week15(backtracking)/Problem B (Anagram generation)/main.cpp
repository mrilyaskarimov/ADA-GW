//
//  main.cpp
//  Problem B (Anagram generation)
//
//  Created by Ilyas Karimov on 23.12.20.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[100];
int i, n;

int cmp( char a, char b){
    if(toupper(a) != toupper(b)) return toupper(a) < toupper(b);
    return a<b;
}
int main()
{
    scanf("%d\n", &n);
    while(n--){
        scanf("%s", s);
        int len = strlen(s);
        sort(s, s+len, cmp);
        do {
          printf("%s\n",s);
        } while(next_permutation(s,s+len,cmp));

    }
}
