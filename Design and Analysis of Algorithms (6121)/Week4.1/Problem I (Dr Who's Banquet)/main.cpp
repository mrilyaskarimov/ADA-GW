//
//  main.cpp
//  Problem I (Dr Who's Banquet)
//
//  Created by Ilyas Karimov on 10/11/20.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> pq;
int num; char c;

bool chat(priority_queue<int> pq){
    
    while(!pq.empty()){
        
        int temp = pq.top();
        pq.pop();
        queue<int>new_q;
        while(temp--){
            if(pq.empty()) return false;
            if(pq.top()!=1) new_q.push(pq.top()-1);
            pq.pop();
        }
        while(!new_q.empty()){
            pq.push(new_q.front());
            new_q.pop();
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    while(scanf("%d%c", &num, &c)==2){
        pq.push(num);
        if(c == '\n'){
            printf(chat(pq) ? "ok\n\n" : "fail\n\n");
           
            while(!pq.empty()){
                pq.pop();
            }
        }
    }
}


//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//priority_queue<int> pq;
//int n;
//char c;
//
//bool process(priority_queue<int> &q)
//{
//    while (!q.empty())
//    {
//        int v = q.top(); q.pop();
//        queue<int> add;
//        while (v--)
//        {
//            if (q.empty()) return false;
//            if (q.top() != 1) add.push(q.top() - 1);
//            q.pop();
//        }
//        while (!add.empty())
//        {
//            q.push(add.front());
//            add.pop();
//        }
//    }
//    return true;
//}
//
//int main() {
//    //Читаем числа одной строки (одного теста). Когда после числа будет прочитан символ '\n',
//    //произойдет обработка данных.Если ответ утвердительный, то выводим ok, иначе fail.
//    while (scanf("%d%c", &n, &c) == 2)
//    {
//        pq.push(n);
//        if (c == '\n')
//        {
//            printf(process(pq) ? "ok\n\n" : "fail\n\n");
//            //Чистим очередь для ее использования в следующем тесте.
//            while (!pq.empty()) pq.pop();
//        }
//    }
//    return 0;
//}
