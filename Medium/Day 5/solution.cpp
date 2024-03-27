// your code here
//Code by Jagpreet153
// Day 5 medium
#include <bits/stdc++.h>
using namespace std;
// Function to calculate processing fee
double calculateFee(double amount, double percentage) {
    return amount * (percentage / 100);
}
int main() {
    int n,i; 
    double f,fe1,fe2,mergedFee; 
    // Input the number of accounts and processing fee percentage
    cin>>n>>f;
    // Input the maximum processing fee limit for each individual account
    // priority queue is used to store the processing fee of each account in ascending order and get the minimum fee account in less time 
    priority_queue<double, vector<double>, greater<double>> minHeap;
    for (i=0;i<n;i++) {
        double fee;
        cin>>fee;
        minHeap.push(fee);
    }
    // Merge accounts until only one remains
    while(minHeap.size()>1){
        double fe1 = minHeap.top();
        minHeap.pop();
        fe1-=calculateFee(fe1, f);
        double fe2=minHeap.top();
        minHeap.pop();
        fe2-=calculateFee(fe2, f);
        double mergedFee=fe1+fe2;
        minHeap.push(mergedFee);
    }
    // Output the maximum amount that can remain in the account
    cout<<minHeap.top()<<endl;
    return 0;
}