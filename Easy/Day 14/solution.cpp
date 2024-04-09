// Write your code here
#include<bits/stdc++.h>
using namespace std;
    
int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.find(s2) == string::npos) {
        cout<<-1<<endl;
    }   
    else{
        cout<<s1.find(s2)<<endl;
    }
    return 0; 
}