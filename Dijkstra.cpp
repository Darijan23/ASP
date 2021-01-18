#include <bits/stdc++.h>

using namespace std;

#define MAXN 100001
const int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s;
    cin >> n >> m >> s;

    vector<pair<int, int>> g[MAXN];

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int dist[MAXN];
    memset(dist, INF, sizeof(dist));

    priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s] = 0;
    pq.push({dist[s], s});

    while (!pq.empty()) {
        int d, u;

        tie(d, u) = pq.top();
        pq.pop();

        if (dist[u] < d) continue;

        for (auto e : g[u]) {
            int v, wuv;
            tie(v, wuv) = e;

            if (dist[u] + wuv < dist[v]) {
                dist[v] = dist[u] + wuv;

                pq.push({dist[v], v});
            }
            
        }
    }

    for (int u = 1; u <= n; u++) {
        cout << (dist[u] < INF ? dist[u] : -1) << "\n";
    }
    cout << endl;
    

    return 0;
}