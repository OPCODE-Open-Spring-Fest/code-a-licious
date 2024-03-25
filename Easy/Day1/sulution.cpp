// Write your solution here
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int k;
    cin >> k;
    int k1=2*k-1; //for the case with total odd factors
    int k2=2*k; //for the case with total even factors
    int num1 = 1;
    int num2=1;
    while (true) {
        int count = 0; //counting number of factors
        for (int i = 1; i <= num1; ++i) {
            if (num1 % i == 0)
                count++;
        }
        if (count == k1) 
            break;
        num1++;
    }
    while (true) {
        int count = 0;
        for (int i = 1; i <= num2; ++i) {
            if (num2 % i == 0)
                count++;
        }

        if (count == k2) 
            break;
         num2++;
    }
       if (ceil((double)sqrt(num1)) == floor((double)sqrt(num1)) && (num1 <=num2)) //checking for perfect square as only perfect squares have total odd factors
        cout << num1 << endl;
    else
        cout << num2 << endl; 

    return 0;
}