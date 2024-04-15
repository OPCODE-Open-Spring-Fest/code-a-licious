// Write your code here.
#include <bits/stdc++.h>
using namespace std;
    
int main(){
    int n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    for (int i = 0; i<n; i++){
        if(x>0 && s[i] == 'x'){
            x--;
        }
        else if(x>=0 && s[i] == 'o'){
            x++;
        }

    }
    cout<<x<<endl;

    

    return 0;
}