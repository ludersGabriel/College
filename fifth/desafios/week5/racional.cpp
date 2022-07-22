#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll a, b, c;
  ll ret;

  cin >> a >> b >> c;
  ll delta = b * b - 4 * a * c;
  ret = (ll) sqrt(delta);

  ret * ret == delta ? cout << 'Y' : cout << 'N';
}