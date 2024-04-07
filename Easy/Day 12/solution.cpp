// your code here
#include<bits/stdc++.h>
using namespace std;
string Good(string s) {
        stack<char> st;
        for (auto& ch : s) {
            if (!st.empty() && ch != st.top() &&
                (toupper(ch) == st.top() || ch == toupper(st.top())))
                st.pop();
            else
                st.push(ch);
        }
        string output = "";
        while (!st.empty()) {
            output = st.top() + output;
            st.pop();
        }
        return output;
    }
int main(){
string s ;
cin>>s;
string k  = Good(s);
if(k.empty()){
    cout<<-1<<endl;
}
else{
    cout<<k<<endl;
}
   return 0;
}
