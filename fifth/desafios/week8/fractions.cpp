#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

vector<ll> quotients;

ll _gcd /* O(lg min(a, b)) */ (ll a, ll b) {

  if (b == 0) { return a; }

  quotients.push_back(a/b);
  
  return _gcd(b, a%b);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll t;
  cin >> t;

  for(; t--;){
    int n, d;
    cin >> n >> d;
    
    quotients.clear();
    _gcd(n, d);
    
    string ret = string("[") + to_string(quotients[0]) + ";";    
    for(int i = 1; i < quotients.size(); i++) ret += to_string(quotients[i]) + ",";
    ret[ret.length() - 1] = ']';
    cout << ret << '\n';
  }
}