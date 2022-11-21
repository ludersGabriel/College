double prim(
  int src, 
  vector<vector<edge>>& g, 
  vector<double>& d, 
  vector<int>& vis, 
  vector<vector<bool>>& roads,
  map<int, pair<int, int>>& coords,
  int custo
) {
  double sum = 0;
  priority_queue<pair<double, int>,
  vector<pair<double, int>>, greater<pair<double, int>>> Q;
  Q.push(make_pair(d[src] = 0, src));
  while (!Q.empty()) {
    auto [c, u] = Q.top(); Q.pop();
    if (vis[u]) { continue; }
    vis[u] = true;
    sum += c;

    for (auto [v, w] : g[u])
      if (!vis[v] && w < d[v])
        Q.push(make_pair(d[v] = w, v));

    for(int v = 0; v < N; v++){
      if(vis[v]) continue; 
      
      if(roads[u][v]) continue;
      
      double w = euclidian(
        coords[v].first,
        coords[v].second,
        coords[u].first,
        coords[u].second
      ) * custo;

      if(w < d[v])
        Q.push(make_pair(d[v] = w, v));
      
    }
  }
  return sum;
}