// your code here
#include <iostream>
using namespace std;

int main() {
    
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1;
    cin >> h2 >> m2 >> s2;

   
    int start = h1 * 3600 + m1 * 60 + s1;
    int end = h2 * 3600 + m2 * 60 + s2;
    int difference = end - start;

    
    int hours = difference / 3600;
    int minutes = (difference % 3600) / 60;
    int seconds = difference % 60;

    cout << hours << " " << minutes << " " << seconds << endl;

    return 0;
}
