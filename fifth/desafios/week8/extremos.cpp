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

  int n;
  cin >> n;
  for(; n--;){
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    int ret = 2;

    if(ax == bx) ret += abs(ay - by ) - 1;
    else if(ay == by) ret += abs(ax - bx) - 1;
    else ret += gcd(abs(ax - bx), abs(ay - by)) - 1;

    cout << ret << '\n';
    
  }


}