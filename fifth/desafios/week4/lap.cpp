#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(int p, int k, int c, vector<int>& v){
  if(p >= v.size()) {
    return 0;
  }
  if(k <= 0){
    return 0;
  }

  ll sum, sum2; sum = sum2 = 0;
  
  sum  += f(p + c, k - 1, c, v);

  if(k * c <= (v.size() - (p + 1))){
    sum2 = v[p];
    sum2 += f(p + 1, k, c, v);
  }

  return sum > sum2 ? sum : sum2;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, k, c;
  cin >> n >> k >> c;
  vector<int> v (n);
  for(auto& el : v){
    cin >> el;
  }

  ll soma = f(0, k, c, v);

  cout << soma;

}