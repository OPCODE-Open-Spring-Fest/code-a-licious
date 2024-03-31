// your code here
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool can_build_raft(vector<int>& logs, int E, int raft_length) {
    int total_beams = 0;
    for (int log : logs) {
        total_beams += log / raft_length;
    }
    return total_beams >= E;
}

int raft(vector<int>& logs, int E) {
    int left = 1;
    int right = *max_element(logs.begin(), logs.end());

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (can_build_raft(logs, E, mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

int main() {
    int N, E;
    cin >> N >> E;
    vector<int> logs(N);
    for (int i = 0; i < N; ++i) {
        cin >> logs[i];
    }

    int max = raft(logs, E);
    cout << max << endl;

    return 0;
}
