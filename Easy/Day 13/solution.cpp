// your code here
#include <bits/stdc++.h>
using namespace std;

int isPalindrome(int N) {
    string str = to_string(N);
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i]!= str[str.length() - i - 1]) {
            return -1;
        }
    }

    return 1;
}

int main() {
    int N;
    cin >> N;
    cout << isPalindrome(N) << endl;

    return 0;
}
