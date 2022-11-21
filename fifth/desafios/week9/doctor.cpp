#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = int;
const ll oo = 1987654321987654321;
using ii = pair<int, int>;
const int inf = 1987654321;

int tk = 0;
void dfs(int u, int p, vector<vector<edge>>& g, set<int>& arti, vector<int>& tin, vector<int>& low) {
  tin[u] = low[u] = tk++; int ch = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    else if (tin[v] == -1) {
      dfs(v, u, g, arti, tin, low); 
      ch++;
      if ((low[v] >= tin[u] && p != u) ||
      (ch >= 2 && p == u))
        arti.insert(u);
            
      low[u] = min(low[u], low[v]);
    } else { 
      low[u] = min(low[u], tin[v]); 
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int t;
  cin >> t;
  
  for(; t--;){
    int m, n;
    cin >> n >> m;

    vector<vector<edge>> g(n);
    vector<pair<int, int>> eds;

    for(; m--;){
      int u, v;
      cin >> u >> v;
      u--; v--;
      eds.push_back(make_pair(u, v));
      g[u].push_back(v);
      g[v].push_back(u);
    }

    tk = 0;
    vector<int> low(n);
    vector<int> tin(n, -1);
    set<int> arti;
    for (int u = 0; u < n; u++) { 
      dfs(u, u, g, arti, tin, low); 
    }

    cout << arti.size() << '\n';

  }
}