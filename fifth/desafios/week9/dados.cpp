#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = int;
const ll oo = 1987654321987654321;
using ii = pair<int, int>;
const int inf = 1987654321;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<pair<vector<int>, int>> g(n, {vector<int> (m, -1), 0});

  for(int i = 0; i < n; i++){
    int ui;
    cin >> ui;
    g[i].second = ui;
    for(int k = 0; k < ui; k++){
      int el;
      cin >> el;
      el--;
      g[i].first[el] = 1;
    }
  }

  vector<bool> f(n, true);
  for(int u = 0; u < n; u++){
    for(int v = 0; v < n; v++){
      if(v == u) continue;

      bool isSubset = true;
      if(g[u].second <= g[v].second){
        for(int k = 0; k < m; k++){ 
          if(g[u].first[k] != -1 && g[v].first[k] == -1){
            isSubset = false;
            break;
          }
        }
      }
      else isSubset = false;
      
      if(isSubset){
        if(g[u].second == g[v].second){
          if(u < v){
            f[v] = false;
          }else{
            f[u] = false;
          }
          continue;
        }
        f[v] = false;
      }
    }
  }

  for(int i = 0; i < n; i++){
    if(f[i]) cout << i << '\n';
  }

}