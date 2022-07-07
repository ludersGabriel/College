#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using il = long;


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll amount, errorAmount;
  ll tmp;
  vector<ll> a;

  for(; cin >> amount;){
    errorAmount = 0;
    a.clear();

    for(ll i = 0; i < amount; i++){
      cin >> tmp;
      a.push_back(tmp);
    }

    for(ll i = 0; i < amount / 2; i++){
      cin >> tmp;

      errorAmount += abs(a[i] + a[a.size() - 1 -i] - tmp);
    }

    cout << errorAmount << "\n";

  }

}