// Write your code here
#include <bits/stdc++.h>
using namespace std;

int main() {
    float x1,y1,r1,x2,y2,r2;
  cin>>fixed >> setprecision(3)>>x1>>y1>>r1>>x2>>y2>>r2;
  float check=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
if(check>r1+r2 || check<fabs(r1-r2)){
    cout<<"0"<<endl;
}
else if(check<r1+r2){
    cout<<"2"<<endl;
}
else if(check==r1+r2 || check==fabs(r1-r2)){
    cout<<"1"<<endl;
}
else{
    cout<<"-1"<<endl;
}
 

    return 0;
}
