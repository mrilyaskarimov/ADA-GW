//
//  main.cpp
//  9643
//
//  Created by Ilyas Karimov on 9/10/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>
int gcd (int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a >=b) return gcd (a%b, b);
    return gcd (a, b%a);

}
int lcd (int a, int b) return a/ gcd (a,b) *b ;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
