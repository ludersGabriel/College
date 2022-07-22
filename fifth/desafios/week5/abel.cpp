#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int op_inclusive(
  vector<int>& t,
  int l, 
  int r, 
  int ti = 1, 
  int tl = 1, 
  int tr = 1
){
  if(l > r) return 1;
  if(l == tl && r == tr) return t[ti];
  int tm = (tl + tr) / 2;
  return 
    op_inclusive(t, l, min(r, tm), ti * 2, tl, tm)
    * op_inclusive(t, max(l, tm + 1), r, ti * 2 + 1, tm + 1, tr);
}

void set_value(vector<int>& t, int i, int v, int ti = 1, int tl = 1, int tr = 1){
  if(tl == tr) {
    t[ti] = v;
    return;
  }

  int tm = (tl + tr) / 2;
  if(i <= tm) set_value(t, i, v, ti * 2, tl, tm);
  else set_value(t, i, v, ti*2 + 1, tm+1, tr);

  t[ti] = t[ti*2] * t[ti*2 +1];
}

void build(vector<int>& src, vector<int>& t, int ti = 1, int tl = 1, int tr = 1){
  if(tl == tr){
    if(tl < src.size()) {
      if(src[tl] > 0) t[ti] = 1;
      else if(src[tl] < 0) t[ti] = -1;
      else t[ti] = 0;
    }
    
    return;
  }
  int tm = (tl + tr) / 2;
  build(src, t, ti*2, tl, tm);
  build(src, t, ti*2 + 1, tm+1, tr);
  t[ti] = t[ti*2] * t[ti*2 + 1];
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  char c;
  int n, k, a, b;
  
  cin >> n >> k;
  
  vector<int> x (n + 1);
  vector<int> t ((n + 1)*4);
  for(int i = 1; i <= n; i++) cin >> x[i];
  build(x, t, 1, 1, n);

  for(; k--;){
    cin >> c >> a >> b;

    if(c == 'A') {
      if(b > 0) b = 1;
      else if(b < 0) b = -1;
      else b = 0;

      set_value(t, a, b, 1, 1, n);
    }
    else{
      ll ret = op_inclusive(t, a, b, 1, 1, n);
      if(ret > 0) cout << '+';
      else if(ret < 0) cout << '-';
      else cout << '0';
    } 
  }
}