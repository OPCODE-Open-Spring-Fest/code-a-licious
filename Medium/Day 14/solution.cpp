#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> A)
{
    int n = A.size();
    sort(A.begin(), A.end());
    int count = 0;
    for (int i = n - 1; i >= 1; i--) {
        int l = 0, r = i - 1;
        while (l < r) {
            if (A[l] + A[r] > A[i]) {
                count += r - l;
                r--;
            }
            else
                l++;
        }
    }
    cout << count;
}
int main()
{

    int n;
    cin>>n;
    vector<int> A;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    solve(A);
}
