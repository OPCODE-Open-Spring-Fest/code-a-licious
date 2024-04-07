// your code here
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int minOperations(vector<int>& arr) {
    unordered_map<int, int> frequency;
    int maxFreq = 0;
    

    for (int num : arr) {
        frequency[num]++;
        maxFreq = max(maxFreq, frequency[num]);
    }
    
   
    return arr.size() - maxFreq;
}

int main() {
    int t;
    cin >> t; 
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
    
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
      
        cout << minOperations(arr) << endl;
    }
    
    return 0;
}
