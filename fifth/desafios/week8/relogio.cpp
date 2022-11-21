#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll gcd /* O(lg min(a, b)) */ (ll a, ll b) {
  if (b == 0) { return a; }
  return gcd(b, a%b);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll h, m, s;
  cin >> h >> m >> s;

  ll match = gcd(h, gcd(m, s));
  cout << match << '\n';
  int ith = h / match;
  int itm = m / match;
  int its = s / match;

  int ih, im, is;
  ih = im = is = 0;
  for(; ih < h; ih += ith, im += itm, is += its)
    cout << ih << ' ' << im << ' ' << is << '\n'; 


}