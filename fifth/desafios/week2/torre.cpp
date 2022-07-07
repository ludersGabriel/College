#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using il = long;


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  stack<int> ms;
  int n, alt;
  char ori;

  for(cin >> n; n; n--){
    cin >> alt >> ori;

    if(ori == 'L'){
      if(ms.empty() || ms.top() > alt){
        ms.push(alt);
      }else return !(cout << "N");
    }
    else {
      if(!ms.empty() && ms.top() == alt)
        ms.pop();
      else return !(cout << "N");
    }
  }

  cout << "S";
  return 0;
}