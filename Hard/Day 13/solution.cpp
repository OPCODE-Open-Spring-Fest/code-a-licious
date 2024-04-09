// Write your code here.
// Code by Jagpreet153
// Approach : The code finds a 132 pattern in an array by iterating in reverse. It uses a stack to track potential 132 patterns. If a number is less than the top of the stack, a 132 pattern is found. If not, it pops elements from the stack until a larger number is found.
#include <bits/stdc++.h>
using namespace std;
void find132pattern(vector<int>& nums) {
    int s3 = INT_MIN;
    stack<int> st;
    int k=-1,j=-1;

    for(int i=nums.size()-1;i>=0;i--) 
    {
        if(nums[i]<s3) 
        {
            cout<<"YES"<<endl;
            cout<<i<<" "<<j<<" "<<k<<endl;
            return;
        } 
        else 
        {
            while(!st.empty() && nums[i] > st.top()) {
                s3 = st.top();
                st.pop();
                k = j;
            }
        }
        st.push(nums[i]);
        j = i;
    }
    cout << "NO" << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    find132pattern(a);
    return 0;
}