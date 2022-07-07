#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int t, p, h, f, d, c;

  cin >> t;
  for(; t--;){
    cin >> p >> h >> f >> d >> c;

    p = p / 2;

    if(p < 1){
      cout << "0\n";
      continue;
    } 

    int max, totalFrango, totalCarne, sobras; 
    max = totalFrango = totalCarne = sobras = 0;

    if(c > d){
      totalFrango = f > p ? p : f;
      sobras = p - f > 0 ? p - f : 0;
      totalCarne = sobras > h ? h : sobras; 
    }else {
      totalCarne = p > h ? h : p; 
      sobras = p - h > 0 ? p - h : 0;
      totalFrango = f > sobras ? sobras : f;
    }
    
    max = totalFrango * c + totalCarne * d;   
    cout << max << '\n';
  }
  
}