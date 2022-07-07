#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using il = long;


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  string code;
  int h, m;
  for(; cin >> code >> h >> m;){
    (h + (float)m/60) <= 10 ? cout << "Abel deve cursar " : cout << "Abel deve cancelar " ;
    cout << code << "\n" ;
  }

}