// Write your code here
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x1,y1,r1,x2,y2,r2;
  cin>>x1>>y1>>r1>>x2>>y2>>r2;
 long long check=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

if(check<r1+r2){
    cout<<"2"<<endl;
}
else if(check==r1+r2){
    cout<<"-1"<<endl;
}
else{
    cout<<"0"<<endl;
}
 

    return 0;
}
