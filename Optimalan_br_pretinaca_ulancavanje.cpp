#include <bits/stdc++.h>

using namespace std;


#define MAXN 100
#define ALPHA 127

struct HashTable {
  vector<list<string>> table;
  int size;
  explicit HashTable (int size) : size(size) {
    table.resize(size);
  }

  int hsh(string &k) {
    int ret = 0;
    for (auto c : k) {
      ret += ret*ALPHA + (int)c;
      ret %= size;
    }
    return ret;
  }

  int insert(string &k) {
    for (auto &el : table[hsh(k)]) {
      if (el==k) return 0;
    }
    table[hsh(k)].push_back(k);
    return table[hsh(k)].size();
  }

  bool get(string &k) {
    for (auto &el : table[hsh(k)]) {
      if (el==k) return true;
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int mlo, mhi, n;

  cin >> n >> mlo >> mhi;

  string keys[MAXN];

  for (int i = 0; i < n; i++) cin >> keys[i];

  int m = 0, mn = mhi + 1;

  for (int size = mlo; size <= mhi; size++) {
      HashTable ht(size);
      int sum = 0;

      for (int i = 0; i < n; i++) sum += ht.insert(keys[i]);

      if (sum < mn) {
          mn = sum;
          m = size;
      }
  }
  
  cout << m;

  return 0;
}
