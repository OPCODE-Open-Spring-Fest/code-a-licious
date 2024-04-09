// Write your code here.
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
    // To synchronize the I/O streams for faster I/O operations
    ios::sync_with_stdio(0);
    // To untie cin from cout, which can improve performance
    cin.tie(0);

    // Input the values of 'a' and 'b'
    int target_a, target_b;
    cin >> target_a >> target_b;

    // Loop through all possible values of 'i' from 1 to 10,000
    for (int i = 1; i <= 1e4; ++i) {
        // Calculate 8% and 10% of 'i' and store them in meaningful variables
        int eight_percent = i * 8 / 100;
        int ten_percent = i * 10 / 100;

        // Check if the calculated percentages match the target values of 'a' and 'b'
        if (eight_percent == target_a && ten_percent == target_b) {
            // If matched, output the value of 'i' and terminate the program
            cout << i;
            return 0;
        }
    }

    // If no match is found, output -1
    cout << -1;
}
