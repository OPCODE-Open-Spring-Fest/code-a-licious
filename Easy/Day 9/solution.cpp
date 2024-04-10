// your code here
#include <iostream>

using namespace std;

int maxSubarraySum(int arr[], int n, int x) {
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += arr[i];
    }
    int maxSum = sum;
    for (int i = x; i < n; i++) {
        sum = sum + arr[i] - arr[i - x];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << maxSubarraySum(arr, n, x) << endl;
    }
    return 0;
}

