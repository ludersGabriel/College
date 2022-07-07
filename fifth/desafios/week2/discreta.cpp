#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  set<string> pile;
  string tmp;
  int n, k;
  cin >> n >> k;
  for(n = n * 2; n; n--){
    cin >> tmp;

    auto it = pile.find(tmp);
    if(pile.find(tmp) != pile.end())
      pile.erase(it);
    else
      pile.insert(tmp);

    
    if(pile.size() >= k){
      cout << 7.18808;
      return 0;
    }
  }

  cout << 3.14159;

}