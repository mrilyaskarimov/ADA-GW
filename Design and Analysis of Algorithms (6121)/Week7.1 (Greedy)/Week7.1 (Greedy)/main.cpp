//
//  main.cpp
//  Week7.1 (Greedy)
//
//  Created by Ilyas Karimov on 28.10.20.
//
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    
    int t, n;
    cin >> t;
    int j = 1;
    while (t--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        sort(arr, arr+n);
        
        deque<int> a, v;
        
        for (int i = 0; i < n; i++) {
            a.push_back(arr[i]);
        }
        
        v.push_front(a.front());
        v.push_back(a.back());
        a.pop_front();
        a.pop_back();
        
        int s = abs(v.back() - v.front());
        
        while (!a.empty()) {
            
            int b = abs(a.front() - v.front());
            int c = abs(a.front() - v.back());
            int d = abs(a.back() - v.front());
            int e = abs(a.back() - v.back());
            
            if (b >= c && b >= d && b >= e) {
                s += b;
                v.push_front(a.front());
                a.pop_front();
            }
            else if (c >= b && c >= d && c >= e) {
                s += c;
                v.push_back(a.front());
                a.pop_front();
            }
            else if (d >= e && d >= b && d >= c) {
                s += d;
                v.push_front(a.back());
                a.pop_back();
            }
            else {
                s += e;
                v.push_back(a.back());
                a.pop_back();
            }
        }
        cout << "Case " << j << ": " << s << endl;
        j++;
    }
    return 0;
}
