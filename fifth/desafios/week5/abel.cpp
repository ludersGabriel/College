#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char consulta(vector<int>& x, int ini, int end){
  ll prod = 1LL;
  for(int i = ini; i < x.size() && i <= end; i++){
    prod *= x[i];
  }

  if(prod > 0) return '+';
  if(prod < 0) return '-';

  return '0';
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);


  char c;
  int n, k, a, b;
  
  cin >> n >> k;
  
  vector<int> x (n);
  for(auto& el : x) cin >> el;

  for(; k--;){
    cin >> c >> a >> b;

    if(c == 'A') x[a] = b;
    else cout << consulta(x, a, b);
  }


}