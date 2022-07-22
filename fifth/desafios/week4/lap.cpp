#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define BIGINT -1e9

int f(int p, int k, int c, vector<int>& v, vector<vector<int>>& m){
  if(m[p][k] != BIGINT){
    return m[p][k];
  }
  
  int sum, sum2; 
  sum = (int) BIGINT;
  sum2 = (int) BIGINT;

  if(p + c < v.size() && k - 1 >= 0){
    sum = f(p + c, k - 1, c, v, m);
  }

  if(k * c <= (v.size() - (p + 1))){
    sum2 = v[p];
    if((p + 1) < v.size())
      sum2 += f(p + 1, k, c, v, m);
  }

  if(sum == (int) BIGINT && sum2 == (int) BIGINT) {
    m[p][k] = 0;
    return 0;
  }

  m[p][k] = sum > sum2 ? sum : sum2;
  return m[p][k];
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, k, c;
  cin >> n >> k >> c;
  vector<int> v (n);
  vector<vector<int>> m (n, vector<int> (k + 1, BIGINT));
  for(auto& el : v){
    cin >> el;
  }

  int soma = f(0, k, c, v, m);

  cout << soma;

}