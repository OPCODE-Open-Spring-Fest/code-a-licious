// Write your code here.
#include <iostream>

using namespace std;

void checkFunc(int arr[3][3]){
    if((arr[0][0]==0 && arr[0][1] ==0 && arr[0][2]==0) ||
    (arr[1][0]==0 && arr[1][1] ==0 && arr[1][2]==0) ||
    (arr[2][0]==0 && arr[2][1] ==0 && arr[2][2]==0) ||
    (arr[0][0]==0 && arr[1][0] ==0 && arr[2][0]==0) ||
    (arr[0][1]==0 && arr[1][1] ==0 && arr[2][1]==0) ||
    (arr[0][2]==0 && arr[1][2] ==0 && arr[2][2]==0) ||
    (arr[0][0]==0 && arr[1][1] ==0 && arr[2][2]==0) ||
    (arr[0][2]==0 && arr[1][1] ==0 && arr[2][0]==0))
    cout<<"YES"<<endl;
    else 
    cout<<"NO"<<endl;
}


int main(){
    int arr[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    int n;
    cin>>n;
    int a[n];
    for(int k=0;k<n;k++)
    {
        cin>>a[k];}
        int c=0;
        for (int i=0;i<3 && c<n;i++){
        
        for(int j=0;j<3;j++)
        {
            if(a[c]=arr[i][j])
            {
                arr[i][j]=0;
                break;
            }
            
        }c++;}
    
    checkFunc(arr);
    
}
