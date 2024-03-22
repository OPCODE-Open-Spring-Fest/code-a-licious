// Write your solution here
#include<bits/stdc++.h>
using namespace std;
int function3(int a ){
    int count = 0;
    for(int x = 1 ;x<=sqrt(a) ; x++){
        if(a%x==0){
       count++;
        }
    }
    return count ;
}
int function2(int p){
     int h = 1;
     while(1){
        if(function3(h)>=p){
             return h;
             break;
        }
        h++;
     }
}
int main(){
    int p ;
    cin>>p;
    cout<<function2(p);
    return 0;
}
