//
//  main.cpp
//  Problem E (Calculator)
//
//  Created by Ilyas Karimov on 28.10.20.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int num, operation = 0;
    scanf("%d", &num);
    while(num != 1){
        if(num%3 == 0) num = num/3;
        else num -= 1;
        
        operation++;
    }
    printf("%d", operation);
}
