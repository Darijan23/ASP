#include <bits/stdc++.h>

using namespace std;


#define MAXN 100
#define ALPHA 127

struct HashTable {
  explicit HashTable (int size) : size(size) {
    table.resize(size);
  }
  vector<string> table;
  int size;

  int hash(string &k) {
    int ret = 0;
    for (auto c : k) {
      ret += ret*ALPHA + (int)c;
      ret %= size;
    }
    return ret;
  }

  int oahash(string &key, int i) {
    return (hash(key) + (i + (long long)i*i)/2) % size;
  }

  pair<int, int> insert(string &key) {
    for (int i = 0; i < size; i++) {
      int slot = oahash(key, i);
      if (table[slot]=="") {
        table[slot] = key;
        return make_pair(slot, i);
      } else if (table[slot]==key) {
        return make_pair(slot, i);
      }
    }
    return make_pair(-1, -1);
  }

  string get(string &k) {
    for (int i = 0; i < size; i++) {
      int slot = oahash(k, i);
      if (table[slot]=="") break;
      if (table[slot]== k) {
        return table[slot];
      }
    }
    return "";
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
      bool allin = true;

      for (int i = 0; i < n; i++) {
          int slot, pos;
          tie(slot, pos) = ht.insert(keys[i]);
          allin &= slot != -1;
          sum += pos;
      }

      if (allin && sum < mn) {
          mn = sum;
          m = size;
      }    
  }
  
  cout << m;

  return 0;
}