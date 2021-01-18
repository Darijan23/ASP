#include <bits/stdc++.h>

using namespace std;

#define MAXN 100001

void dfs(int u, vector<int> *g, bool *been) {
    been[u] = true;

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
  int br = 0;

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
  }

  for (int u = 1; u <= n; u++) {
      if (been[u]) continue;
      dfs(u, graph, been);
      br++;
  }
  
  cout << br;

  return 0;
}