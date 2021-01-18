#include <bits/stdc++.h>

using namespace std;

#define ALPHA 127

struct HashTable {
    int size;
    vector<list<pair<string, int>>> table;

    HashTable(int size) : size(size) {
        table.resize(size);
    }

    int hsh(string &k) {
        int ret = 0;
        for (auto c : k) {
            ret += ret * ALPHA + (int)c;
            ret %= size;
        }
        return ret;
    }

    void insert(string &k, int v) {
        for (auto &el : table[hsh(k)]) {
            if (el.first == k) {
                el.second = v;
                return;
            }
        }
        
        table[hsh(k)].push_back({k, v});
    }

    pair<int, int> get(string &k) {
        int pos = 0;
        for (auto &el : table[hsh(k)]) {
            pos++;
            if (el.first == k) return make_pair(pos, el.second);
        }
        return make_pair(0, 0);
    }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  HashTable ht(m);

  for (int i = 0; i < n; i++) {
      string k;
      int v;

      cin >> k >> v;

      ht.insert(k, v);
  }

  int q;  
  cin >> q;

  for (int i = 0; i < q; i++) {
      string k;
      int pos, v;
      cin >> k;

      tie(pos, v) = ht.get(k);

      cout << v << " " << pos << "\n";
  }
  

  return 0;
}