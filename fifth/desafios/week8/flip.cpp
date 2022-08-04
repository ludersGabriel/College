#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll extgcd /* O(lg min(a, b)) */ (ll a, ll b, ll& x, ll& y) {
  if (b == 0) { x = 1; y = 0; return a; }
  ll g = extgcd(b, a%b, x, y);
  tie(x, y) = make_tuple(y, x - (a/b)*y);
  return g;
}

ll inv(ll a, ll m) {
  ll x, y; extgcd(a, m, x, y);
  return ((x % m) + m) % m;
}

ll crt (vll a, vll m, int t) {
  ll p = 1; 
  for (ll& mi : m) { 
    p *= mi; 
  }
  ll ans = 0;
  for (int i = 0; i < t; i++) {
    ll pp = p / m[i];
    ans = (ans + ((a[i] * inv(pp, m[i])) % p * pp) % p) % p;
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;
  vll a, m;
  for(int i = 0; i < n; i++){
    int f, d;
    cin >> f >> d;

    auto it = find(m.begin(), m.end(), f);
    if(it != m.end()){
      if(a[it - m.begin()] != d){
        cout << -1;
        return 0;
      }
      continue;
    }

    m.push_back(f);
    a.push_back(d);
  }

  cout << crt(a, m, a.size());


}