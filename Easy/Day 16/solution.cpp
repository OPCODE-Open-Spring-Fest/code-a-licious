// Write your code here. 
#include <bits/stdc++.h>
using namespace std;
    
int main(){
    int x,y,n;
    cin>>x>>y>>n;
    if(x*3 < y){
        cout<<x*n<<endl;
    }
    else{
        cout<<(n/3)*y + (n%3)*x<<endl;
    }
    return 0;
}