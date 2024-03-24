// Write your code here
// Write your code here
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int n = INT_MAX;
    int flag = 0;
    for (int i = 1; i < n; i++)
    {
        int count = 0;
        for (int j = 1; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                count++;
            }
            if (count == k)
            {
                cout << i << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }

    return 0;
}
