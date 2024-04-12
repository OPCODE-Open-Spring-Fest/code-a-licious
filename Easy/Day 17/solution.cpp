#include <bits/stdc++.h>
using namespace std;
int main()
{

    pair <int , int> p1;
    pair <int , int> p2;
    pair <int , int> p3;
    cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second ;

    int sum1 = 0;
    sum1 = sum1 ^ p1.first ^ p2.first ^ p3.first;
    int sum2 = 0;
    sum2 = sum2 ^ p1.second ^ p2.second ^ p3.second;

    cout << sum1 << " " << sum2 ;
    return 0;
}