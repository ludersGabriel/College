#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = int;
const ll oo = 1987654321987654321;

void floydWarshall(int u, int v, vector<vector<edge>>& g, vector<vector<ll>>& d, vector<vector<ll>>& next, int n){
  for(int u = 0; u < n; u++){
    for(auto v : g[u]){
      // weight is 1
      d[u][v] = 1;
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

  vector<vector<edge>> adj(n);
  map<string, int> ida;
  map<int, string> vinda;

  vector<bool> vis (n, false);
  vector<vector<ll>> d (n, vector<ll>(n, oo));
  vector<vector<ll>> next(n, vector<ll>(n, oo));

  int count = 0;

  for(; m--;){
    string a, b;
    cin >> a >> b;

    if(ida.find(a) == ida.end()){
      ida[a] = count;
      vinda[count++] = a;
    } 
    if(ida.find(b) == ida.end()){
      ida[b] = count;
      vinda[count++] = b;
    } 

    adj[ida[a]].push_back(ida[b]);
  }

  floydWarshall(1, count - 1, adj, d, next, n);
  
  vector<pair<int, pair<string, string>>> paths;
  double sep = 0;
  for(int u = 0; u < n; u++){
    for(int v = 0; v < n; v++){
      auto p = path(u, v, next);
      if(p.size()){
        paths.push_back(make_pair(p.size(), make_pair(vinda[u], vinda[p[p.size() - 1]])));
        sep += p.size();
      }
    }
  }

  sep /= paths.size();
  sort(paths.begin(), paths.end());

  // for(auto el : paths){
  //   cout << el.second.first << " para " << el.second.second << " com " << el.first << " cliques" << endl;
  // }
  // cout << endl;

  cout << sep << "\n";

  int half = ceil(paths.size() / 2.0);
  half = half == 0 ? half : half - 1;

  auto p = path(ida[paths[half].second.first], ida[paths[half].second.second], next);
  cout << paths[half].second.first << " ";
  for(auto el : p){
    cout << vinda[el] << " ";
  }

}