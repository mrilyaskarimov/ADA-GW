#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<char> st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.size()!=0)
            {
            if((s[i]==')'&&st.top()=='(')||(s[i]=='}'&&st.top()=='{')||(s[i]==']'&&st.top()=='['))
                {
                st.pop();
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    if(st.size()==0)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
