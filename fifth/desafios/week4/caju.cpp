#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  unsigned int n, tmp, sum;
  sum = 0;
  cin >> n;
  for(; cin >> tmp;){
    if(tmp > 10){
      sum += tmp - 10;
    }
  }

  cout << sum;
}