#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll gcd /* O(lg min(a, b)) */ (ll a, ll b) {
  if (b == 0) { return a; }
  return gcd(b, a%b);
}

void factorize /* O(sqrt(n)) */ (ll n) {
  map<ll, ll, greater<int>> factors;

  for (ll i = 2; i*i <= n; i++)
  while (n % i == 0) { 
    n /= i; 
    factors[i]++; 
  }
  if (n > 1) { 
    factors[n]++;
  }

  for(auto [key, value] : factors){
    cout << key << ' ' << value << '\n';
  }

}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll t;
  cin >> t;
  for(; t--;){
    ll n, num;
    num = 1;
    cin >> n;
    for(; n--;){
      ll p, e;
      cin >> p >> e;

      ll mult = 1;
      for(int i = 0; i < e; i++) mult *= p;

      num *= mult;
    }

    factorize(num - 1);
  }

}