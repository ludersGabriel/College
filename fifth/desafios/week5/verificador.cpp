#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void add(vector<int>& bit, int i, int delta){
  for(; i < bit.size(); i += i & (-i))
    bit[i] += delta;
}

int get(vector<int>& bit, int i){
  int ans = 0;
  for(; i > 0; i -= i & (-i))
    ans += bit[i];
  return ans;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n;
  char tmp;
  cin >> n;
  vector<int> bit(n + 1, 0);
  vector<int> elements(n + 1, 0);
  for(int i = 1; i <= n; i++){
    cin >> tmp;
    elements[i] = (tmp - '0');
    add(bit, i, elements[i]);
  }

  int q;
  cin >> q;
  for(; q--;){
    int op;
    cin >> op;
    if(op == 1 || op == 2){
      int a1, b1, a2, b2, v;
      cin >> a1 >> b1 >> a2 >> b2 >> v;
      int op1 = get(bit, b1) - get(bit, a1 - 1);
      int op2 = get(bit, b2) - get(bit, a2 - 1);

      bool equal = op == 1
        ?  ((op1 % 9) + (op2 % 9)) % 9 == v 
        :  ((op1 % 9) * (op2 % 9)) % 9 == v;

      equal ? cout << "YES\n" : cout << "NO\n";

    }else{
      int p, d;
      cin >> p >> d;
      int current = elements[p];
      add(bit, p, d - current);
      elements[p] = d;
    }
  }

}