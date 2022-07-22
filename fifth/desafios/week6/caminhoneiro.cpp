#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = pair<int, int>;
const ll oo = 1987654321987654321;
const int inf = 1987654321;

void floydWarshall(int u, int v, vector<vector<edge>>& g, vector<vector<ll>>& d, vector<vector<ll>>& next, int n){
  for(int u = 0; u < n; u++){
    for(auto [v, w] : g[u]){
      // weight is 1
      d[u][v] = w;
      next[u][v] = v;
    }
  }

  for(int u = 0; u < n; u++){
    d[u][u] = 0;
    next[u][u] = u;
  }

  for (int m = 0; m < n; m++)
  for (int u = 0; u < n; u++)
  for (int v = 0; v < n; v++){
    if(d[u][v] > d[u][m] + d[m][v]){
      d[u][v] =  d[u][m] + d[m][v];
      next[u][v] = next[u][m];
    }
  }
}

vector<ll> path(ll u, ll v, vector<vector<ll>>& next){
  vector<ll> ret;
  
  if(next[u][v] == oo) return ret;

  while (u != v){
    u = next[u][v];
    ret.push_back(u);
  }

  return ret;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  
  vector<vector<ll>> d (n, vector<ll>(n, oo));
  vector<vector<ll>> next(n, vector<ll>(n, oo));
  vector<vector<edge>> g(n);
  for(; m--;){
    int u, v, p;
    cin >> u >> v >> p;
    g[u].push_back(make_pair(v, p));
    g[v].push_back(make_pair(u, p));
  }
  
  floydWarshall(0, 1, g, d, next, n);
  ll minDistance = -oo;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      if(minDistance < d[i][j]) minDistance = d[i][j];
    }

  cout << minDistance;

}