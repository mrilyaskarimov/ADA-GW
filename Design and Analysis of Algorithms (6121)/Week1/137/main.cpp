//
//  main.cpp
//  137
//
//  Created by Ilyas Karimov on 9/10/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> result;

int ebob;
using namespace std;


int gcd (int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a >=b) return gcd (a%b, b);
    return gcd (a, b%a);

}
int main(int argc, const char * argv[]) {
    
    int count;
    cin >> count;
    cin.ignore();
    
    string line, current;
    getline(cin, line);
    
    for (char c : line){
          if (c==' '&&current.length() > 1)
          {
              result.push_back(stoi(current));
              current="";
          }
          else if (c!=' ')
              current = current + c;
      }
      if (current !="") result.push_back(stoi(current));
 
    if(result.size() == 2){
        ebob = gcd(result[0], result[1]);
    }
    else {
        for(int i = 0; i < result.size(); i++){
           ebob = gcd(ebob, result[i]);
        }
    }
    printf("%d", ebob);
}
