// Write your code here.
//Code by Jagpreet153
#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

int main() 
{
    int h, w; 
    cin >> h >> w;
    vector<vector<int> > m(h, vector<int>(w)), dp(h, vector<int>(w, 0));
    for(int i = 0; i < h; i++) 
    {
        string s; 
        cin >> s;
        for(int j = 0; j < w; j++) {
            if(s[j] == '#') m[i][j] = 1;
            else m[i][j] = 0;
        }
    }
    if(m[0][0] == 1) dp[0][0] = 1;
    else dp[0][0] = 0;

    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) 
    {
        if(i == 0 && j == 0) 
        continue;
        if(i == 0) 
        {
            if(m[i][j-1]==0 && m[i][j]) 
            dp[i][j] = dp[i][j-1] + 1;
            else
            dp[i][j] = dp[i][j-1];
        } 
        else if(j == 0) 
        {
            if(m[i-1][j]==0 && m[i][j])
            dp[i][j] = dp[i-1][j] + 1;
            else 
            dp[i][j] = dp[i-1][j];
        } 
        else 
        {
            dp[i][j] = min(dp[i-1][j]+((m[i-1][j]==0 && m[i][j])?1:0), dp[i][j-1]+((m[i][j-1]==0 && m[i][j])?1:0));
        }
    }

    cout << dp[h-1][w-1] << endl;
    return 0;
}   