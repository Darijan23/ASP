#include <bits/stdc++.h>

using namespace std;

#define MAXN 10

vector<int> graph[MAXN];
bool been[MAXN] = {false};

int n, m, num = 0, visited = 0;

void dfs(int u) {
    been[u] = true;
    visited++;

    if(visited == n) num++;

    for (auto v : graph[u]) {
        if (been[v]) continue;
        dfs(v);
    }

    been[u] = false;
    visited--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
  }

  dfs(1);
  cout << num;

  return 0;
}