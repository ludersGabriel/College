#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {int u, v, w; };
const int oo = 1987654321;

int bellman_ford(int src, int dest, int n, vector<edge>& edges, vector<int>& d) {
  d[src] = 0;
  for (int i = 1; i <= n - 1; i++)
  for (auto e : edges)
    if (d[e.u] != oo && d[e.v] > d[e.u] + e.w)
      d[e.v] = d[e.u] + e.w;

  // Verificação de ciclos negativos
  for (auto e : edges)
    if (d[e.u] != oo && d[e.v] > d[e.u] + e.w)
      return -oo;
  return d[dest];
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> pesos(n + 1);

  for(int i = 1; i <= n; i++){
    cin >> pesos[i];
  }

  int m;
  cin >> m;
  vector<edge> edges (m);
  
  for(auto& el : edges){
    int a, b;
    cin >> a >> b;
    el = {a, b, pesos[b] - pesos[a]};
  }

  vector<int> d(n + 1, oo);
  int q, dest;
  cin >> q;
  q--;

  cin >> dest;
  int ret = bellman_ford(1, dest, n, edges, d);
  ret < 3  || ret == oo ? cout << "Não, Edsger..." << '\n' : cout << ret << '\n';

  for(; q--;){
    cin >> dest;
    d[dest] < 3  || d[dest] == oo ? cout << "Não, Edsger..." << '\n' : cout << d[dest] << '\n';
  }

}