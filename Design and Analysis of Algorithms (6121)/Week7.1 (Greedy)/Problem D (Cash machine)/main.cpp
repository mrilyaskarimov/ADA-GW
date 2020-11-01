//
//  main.cpp
//  Problem D (Cash machine)
//
//  Created by Ilyas Karimov on 28.10.20.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int bankNotes [6] = {500, 200, 100, 50, 20, 10};
    int num, result = 0;
    
    scanf("%d", &num);
    for(int i= 0; i< 6 ; i++){
        result += num/bankNotes[i];
        num = num % bankNotes[i];
    }
    if(num > 0) printf("-1\n");
    else printf("%d\n", result);
}
