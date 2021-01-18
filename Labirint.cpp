#include <bits/stdc++.h>

using namespace std;

#define MAXN 101

int xdir[4] = {1, 0, -1, 0};
int ydir[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string lab[MAXN];
    pair <int, int> start;
    
    int n, m;
    bool been[MAXN][MAXN] = {{false}};
    int len = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> lab[i];

        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 'S') {
                start = {i, j};
                break;
            }
        }
    }

    queue <pair <pair <int, int>, int>> q;

    q.push({start, 0});
    been[start.first][start.second] = true;

    while (!q.empty() && !len) {
        pair <int, int> field;
        int dist;

        tie(field, dist) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xc = field.first + xdir[i];
            int yc = field.second + ydir[i];

            if (xc < 0 || xc >= n || yc < 0 || yc >= m) continue;
            else if (been[xc][yc] || lab[xc][yc] == '#') continue;
            else if (lab[xc][yc] == 'F') len = dist + 1;

            q.push({{xc, yc}, dist + 1});
            been[xc][yc] = true;
        }
    }
    
    cout << len;

    return 0;
}