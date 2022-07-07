#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getCombination(vector<ll>& v, ll r, ll a, ll b){
  ll ret = 0;
  vector<bool> test (v.size(), false);
  ll amount;

  for(int s = 1; s < ( 1 << r); s++){
    amount = -1LL;
    ll mult = 1;
    for(int i = 0; i < r; i++){
      if(bool(s & (1 << i))){
        amount += 1;
        mult *= v[i];
      } 
    }
    
    ll add = (b / mult - (a - 1) / mult);
    ret = !(amount % 2) ? ret + add : ret - add; 
    
  }

  return ret;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll a, b, c, tmp;
  cin >> a >> b >> c;
  ll total = b - a + 1LL;
  vector<ll> primes (c);

  for(auto& el : primes){
    cin >> el;
  }

  cout << total - getCombination(primes, primes.size(), a, b);


}