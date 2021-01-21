#include <bits/stdc++.h>

using namespace std;

#define MAXN 26

vector<int> graph[MAXN];
bool been[MAXN], possible[MAXN][MAXN];

void dfs(int s, int u) {
    been[u] = true;
    possible[s][u] = true;

    for (auto &v : graph[u]) if (!been[v]) dfs(s, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        char u, v;
        cin >> u >> v;

        graph[u - 'a'].push_back(v - 'a');
    }

    for (int i = 0; i < MAXN; i++) {
        memset(been, false, sizeof(been));
        dfs(i, i);
    }

    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;

        if (a.size() != b.size()) {
            cout << "no" << '\n';
            continue;
        }

        bool can = true;

        for (int j = 0; j < (int)a.size(); j++) can &= possible[a[j] - 'a'][b[j] - 'a'];
        
        cout << (can ? "yes" : "no") << '\n';
    }

    return 0;
}