// Write your code here.



#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

const long long mod = 10000000000000017LL;

struct Edge {
    int v, lab;
    Edge(int _v, int _lab) : v(_v), lab(_lab) {}
};

void dfs(int u, int cp, int n, vector<vector<int>>& gg, vector<int>& vis, vector<int>& lab, vector<int>& bel, vector<int>& rep) {
    if (u == cp) {
        for (int i = 0; i < n; ++i) {
            cout << lab[bel[i]] << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < 16; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                lab[u] = i;
                bool fg = true;
                for (int v = 0; v < u; ++v) {
                    if (gg[u][v] == 1 && ((lab[u] ^ lab[v]) != 1 && (lab[u] ^ lab[v]) != 2 && (lab[u] ^ lab[v]) != 4 && (lab[u] ^ lab[v]) != 8)) {
                        fg = false;
                        break;
                    }
                    if (gg[u][v] == 0 && ((lab[u] ^ lab[v]) == 1 || (lab[u] ^ lab[v]) == 2 || (lab[u] ^ lab[v]) == 4 || (lab[u] ^ lab[v]) == 8)) {
                        fg = false;
                        break;
                    }
                }
                if (fg) {
                    dfs(u + 1, cp, n, gg, vis, lab, bel, rep);
                    return;
                }
                vis[i] = false;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> pw(n + 1);
    pw[0] = 23333;
    for (int i = 1; i <= n; ++i) {
        pw[i] = (pw[i - 1] * 13331 + 23333) % mod;
    }
    
    vector<int> pa(m), pb(m);
    vector<long long> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        pa[i] = u;
        pb[i] = v;
        g[u] += pw[v];
        g[v] += pw[u];
    }
    
    vector<int> bel(n, -1);
    vector<int> rep;
    int cp = 0;
    for (int i = 0; i < n; ++i) {
        bel[i] = -1;
        for (int j = 0; j < cp; ++j) {
            if (g[i] == g[rep[j]]) {
                bel[i] = j;
                break;
            }
        }
        if (bel[i] == -1) {
            bel[i] = cp;
            rep.push_back(i);
            cp++;
        }
    }
    
    vector<vector<int>> gg(cp, vector<int>(cp));
    for (int i = 0; i < m; ++i) {
        int u = bel[pa[i]];
        int v = bel[pb[i]];
        gg[u][v] = 1;
        gg[v][u] = 1;
    }
    
    vector<int> vis(16);
    vector<int> lab(cp);
    dfs(0, cp, n, gg, vis, lab, bel, rep);
    
    return 0;
}
