// Write your code here
// Code by Jagpreet153
// Approach : Math
#include <bits/stdc++.h>
using namespace std;
int main() {
    double x1, y1, r1, x2, y2, r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    double dist = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    if (dist > r1 + r2) 
        cout << 0 << endl;  // Circles are separate
    else if (dist == r1 + r2) 
        cout << 1 << endl;  // Circles touch each other externally
     else if (dist + min(r1, r2) < max(r1, r2)) 
        cout << 0 << endl;  // One circle is inside the other and not touching
    else if (dist==0) 
        cout << -1 << endl;  // Circles coincide
    else if (dist + min(r1, r2) == max(r1, r2)) 
        cout << 1 << endl;  // Circles touch each other internally
     else 
        cout << 2 << endl;  // Circles intersect at two points
    return 0;
}
