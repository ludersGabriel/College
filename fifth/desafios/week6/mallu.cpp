#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = int;

void explore(int u, vector<bool>& visited, vector<vector<edge>>& adj){
  visited[u] = true;
  for(auto v : adj[u])
    if(!visited[v])
      explore(v, visited, adj);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<vector<edge>> adj(n);
  vector<bool> visited(n, false);

  for(; m--;){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int count = 0;
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      explore(i, visited, adj);
      count++;
    }
  }

  cout << count;
}