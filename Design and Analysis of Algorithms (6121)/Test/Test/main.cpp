//
//  main.cpp
//  Test
//
//  Created by Ilyas Karimov on 04.02.21.
//



#include <iostream>
#include <cstring>
#include <stack>
#include <string>

using namespace std;
char str[256];
stack <char> st;
int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    int count  = 0;
    for(int i = 0; i< str.size(); i++){
        if(str[i] == '(' "" str[i] == '('  str[i] == '(' ){
            st.push('(');
  
        }
        if(str[i] == ')') {
            if(!st.empty()){
                st.pop();
                c1--;
            }
        }
        if(str[i] == '{'){
            st.push('{');
            c2++;
        }
        if(str[i] == '}') {
            if(!st.empty()){
                st.pop();
                c2 --;
            }
        }
        if(str[i] == '['){
            st.push('[');
            c3++;
        }
        if(str[i] == ']') {
            if(!st.empty()){
                st.pop();
                c3--;
            }
        }
    }
    
    if((c1 == 0) & (c2==0) & (c3 == 0)) puts("yes");
    else puts("no");
}



//#include <iostream>
//#include <stack>
//using namespace std;
//int main(){
//    stack<char> x;
//    string a;
//    cin>>a;
//    int i,k=0;
//    for(i=0;i<a.size();i++){
//        if(a[i]=='('||a[i]=='['||a[i]=='{')
//        x.push(a[i]);
//        else
//        if(!x.empty()){
//            if((a[i]==')'&&x.top()=='(')||(a[i]==']'&&x.top()=='[')||(a[i]=='}'&&x.top()=='{')){
//                x.pop();
//                }
//            else{
//                k=1;
//                break;
//                }
//            }
//        else {
//            k=1;
//            break;
//            }
//        }
//        if(k==0 && x.size()==0)
//            cout<<"yes"<<endl;
//        else
//            cout<<"no"<<endl;
//    return 0;
//    }
