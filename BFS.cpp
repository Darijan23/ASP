#include <bits/stdc++.h>

using namespace std;

#define MAXN 100001

void bfs(int start, vector<int> *g, int* dist) {
    bool been[MAXN] = {};
    queue<int> q;

    dist[start] = 0;
    been[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : g[u]) {
            if (been[v]) continue;
            been[v] = true;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }    
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> graph[MAXN];
  int dist[MAXN] = {};

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
  }

  bfs(1, graph, dist);

  for (int i = 1; i <= n; i++) {
      cout << dist[i] << '\n';
  }

  return 0;
}