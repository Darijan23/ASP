#include <bits/stdc++.h>

using namespace std;

#define MAXN 100001

void dfs(int u, vector<int> *g, bool *been) {
    been[u] = true;
    sort(g[u].begin(), g[u].end());
    
    cout << u << '\n';

    for (auto v : g[u]) {
        if (been[v]) continue;
        dfs(v, g, been);
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> graph[MAXN];
  bool been[MAXN] = {false};

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
  }

  dfs(1, graph, been);

  return 0;
}