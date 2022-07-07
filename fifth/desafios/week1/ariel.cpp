#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int lastDigit(string& str){
  return str[str.size() - 1] - '0';
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  string a, b;
  int amount;

  cin >> amount;
  for(int i = 0; i < amount; i++){
    cin >> a >> b;
    (lastDigit(a) % 2) == (lastDigit(b) % 2) ? cout << "PARCEIROS\n" : cout << "NAO PARCEIROS\n";
  }
}