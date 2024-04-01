// Code by Jagpreet153
// Approach maths and general observation
#include <bits/stdc++.h>
using namespace std;
int main() {
    int S,K,A,B;
    cin>>S>>K>>A>>B;
    for(int D=1;D<=A;D++) {
        int C=A-K*D;
        if (C<=0) {
            continue;
        }
        int N =(B-S*C)/D;
        if (S*C+N*D == B && N >= 0) {
            cout<< N<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
