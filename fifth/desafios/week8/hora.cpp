#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll gcd /* O(lg min(a, b)) */ (ll a, ll b) {
  if (b == 0) { return a; }
  return gcd(b, a%b);
}

ll lcm /* O(lg min(a, b)) */ (ll a, ll b) {
  return a*(b/gcd(a, b));
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll h, m, s;
  cin >> h >> m >> s;

  cout << (360/h) / gcd(360/h, gcd(360/m,360/s)) << endl; 

  ll sm = m * s;
  ll sh = sm * h;

  ll it = gcd(sh, gcd(sm, s));
}