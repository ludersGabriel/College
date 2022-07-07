#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int checaRest(vector<int>& s, vector<pair<int,int>>& rest, int k){
  for(auto& el : rest){

    auto first = find(s.begin(), s.begin() + k, el.first);
    auto second = find(s.begin(), s.begin() + k, el.second);

    if(second < first){
      return 0;
    }
  }

  return 1;
}

void gen(vector<int>& s , vector<bool>& chosen, vector<pair<int,int>>& rest, int k, int n){
  // checar s com condic
  if(!checaRest(s, rest, k)) return;
  
  if(k == n){
    for(int i = 0; i < n; i++){
      cout << s[i] << ' ';
    }
    cout << "\n"; 
    return;
  }
  for(int i = 1; i <= n; i++)
    if(!chosen[i]){
      chosen[i] = 1;
      s[k] = i;
      gen(s, chosen, rest, k+1, n);
      chosen[i] = 0;
    }
}


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, c;

  cin >> n >> c;

  vector<pair<int, int>> rest (c);
  vector<int> s (n);
  vector<bool> chosen (n);

  int tmp1, tmp2;
  
  for(auto& el : rest){
    cin >> tmp1 >> tmp2;
    el = make_pair(tmp1, tmp2);
  }

  gen(s, chosen, rest, 0, n);
  cout << "\n";

}