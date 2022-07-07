#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define PAREDE '#'
#define BURACO '_'

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int t, guardas;
  string s;
  char c;

  cin >> t;

  for(int i = 1; i <= t; i++){
    cin >> s;
    guardas = 0;
    
    for(int j = 0; j < s.length();){
      c = s[j];
      if(c == BURACO){
        j+=3;
        guardas++;
      }
      else{
        j++;
      }
    }

    cout << "Caso " << i << ": " << guardas << '\n';
  }
}