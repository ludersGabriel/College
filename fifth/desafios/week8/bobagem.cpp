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

  ll t;
  cin >> t;
  for(; t--;){
    ll n, num;
    num = 0;
    cin >> n;
    for(; n--;){
      ll p, e;
      cin >> p >> e;

      ll mult = 1;
      for(int i = 0; i < e; i++) mult *= p;

      num += mult;
    }

    cout << num << '\n';
  }
  


}