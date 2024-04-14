// Write your code here. 
//Code by Jagpreet153
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s += 'C';
    t += 'C';
    string a, b;
    for (int i = 0;i <= n;++i) {
        if (t[i] != 'C')
            a += s[i], b += t[i];
        else {
            if (s[i] != 'C') {
                cout << "No\n";
                return;
            }

            int cnta = count(a.begin(),a.end(), 'A');
            int cntb = count(b.begin(),b.end(), 'A');
            int del = cntb - cnta;
            if (del < 0) {
                cout << "No\n";
                return;
            }
            for (auto& c : a) {
                if (c == 'C') {
                    if (del) {
                        del--;
                        c = 'A';
                    }
                    else
                        c = 'B';
                }
            }
            int cnt = 0;
            for (int i = 0;i < a.size();++i) {
                cnt += (a[i] == 'A');
                cnt -= (b[i] == 'A');
                if (cnt < 0) {
                    cout << "No\n";
                    return;
                }
            }
            a.clear();
            b.clear();
        }
    }
    cout << "Yes\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}