// your code here
// Code by Jagpreet153
// Approach: For each cube, we will decrement the number of sides that are connected to another cube and count the remaining sides.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> sides(n+1, 6); // each cube has 6 sides
        for(int i = 1; i <= n; i++) {
            int cube, connected;
            cin >> cube;
            char c;
            cin >> c; // read the colon character
            while(cin >> connected && connected) {
                sides[cube]--; // one side of cube is connected
            }
        }
        int total = 0;
        for(int i = 1; i <= n; i++) {
            total += sides[i];
        }
        cout << total << endl;
    }
    return 0;
}