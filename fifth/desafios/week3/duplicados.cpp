#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  map<ll, ll> hash;

  ll n, k;
  cin >> n >> k;

  vector<ll> v(n);
  for(auto& el : v){
    cin >> el;
    hash[el] = 0;
  }

  for(int i = 0; i < k; i++){
    hash[v[i]] += 1;
  }

  ll bigger = -1;
  for(auto& el : hash){
    if(el.second > bigger) bigger = el.second;
  }

  for(int i = k; i < n; i++){
    ll leaving = v[i - k];
    ll entering = v[i];

    hash[leaving] -= 1;
    hash[entering] += 1;

    if(hash[entering] > bigger) bigger = hash[entering];
  }


  cout << bigger;

}