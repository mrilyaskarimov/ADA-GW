//
//  main.cpp
//  Problem N (Elegant permuted su)
//
//  Created by Ilyas Karimov on 11.11.20.
//

#include <iostream>
#include <deque>
#include <algorithm>
#define MAX 1001
using namespace std;

int mod(int a, int b){
    if (b-a<0) return -1*(b-a);
    return b-a;
}

int main(int argc, const char * argv[]) {
    int num;
    long long sum =0;
    scanf("%d", &num);
    int c =1;
    while(num--){
        int n;
        scanf("%d", &n);
        int m[n];
        for(int i=0;i<n;i++) scanf("%d", &m[i]);
        sort(m, m+n);
        
        deque <int> a,v;
        for(int i=0;i<n;i++) a.push_back(m[i]);
        v.push_front(a.front());
        v.push_back(a.back());
        
        a.pop_front();
        a.pop_back();
 
        sum = mod(v.front(), v.back());
        
        while(!a.empty()){
            int ff = mod(v.front(), a.front());
            int vf = mod(v.back(), a.front());
            int fv = mod(v.front(), a.back());
            int vv = mod(v.back(), a.back());
            
            if(ff>= vf && ff >=fv && ff>=vv){
                sum+= ff;
                v.push_front(a.front());
                a.pop_front();
            }
            else if(vf>=ff && vf >= fv && vf>=vv){
                sum+= vf;
                v.push_back(a.front());
                a.pop_front();
            }
            else if(fv>=ff&& fv>=vf && fv>=vv){
                sum+= fv;
                v.push_front(a.back());
                a.pop_back();
            }
            else{
                sum+= vv;
                v.push_back(a.back());
                a.pop_back();
            }
        }
        printf("Case %d: %lld\n",c, sum);
        c++;
    }
}
