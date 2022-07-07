#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  vector<int> v;
  int n, tmp;
  for(cin >> n; n; n--){
    cin >> tmp;
    v.push_back(tmp);
  } 
  sort(v.begin(), v.end());

  cout << v.size() / 2 << " " << v[v.size() / 2] - v[v.size() / 2 - 1];

}