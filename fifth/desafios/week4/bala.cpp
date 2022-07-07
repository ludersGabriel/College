#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll m[30001][5];
map<ll, ll> coins = {
  {1, 0},
  {5, 1},
  {10, 2},
  {25, 3},
  {50, 4}
};

void conta(ll corrente, ll moeda, ll& count){
  if(m[corrente][coins[moeda]]){
    count += m[corrente][coins[moeda]];
    return;
  }

  if(corrente == 0 || moeda == 1) {
    count++;
    return;
  }
  
  ll oldCount = count;
  for(auto& x : coins){
    if(corrente >= x.first && moeda >= x.first)
      conta(corrente - x.first, x.first, count);
  }

  m[corrente][coins[moeda]] = count - oldCount;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  memset(m, 0, 30001*5*sizeof(ll));

  ll n, count, init;
  for(; cin >> n;){
    count = 0;
    
    conta(n, 50, count);
    cout << count << '\n';
  }
}