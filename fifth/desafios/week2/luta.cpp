#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int getPrioFight(string& s){
  if(
    !s.compare("idjassu") 
    || !s.compare("galhofa")
    || !s.compare("aipenkuit")
  ) return 0;
  
  return 1;
}

int getPrioHour(float i){
  return !(i >= 13.0);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  // tuple for fight, time, age, class, index
  vector<tuple<int, int, int, int, int>> v;

  char colon;
  string fight;
  float time, tmp;
  int age, classification;

  int n, spots;
  cin >> n >> spots;
  for(int i = 1; i <= n; i++){
    cin >> fight >> time >> colon;
    cin >> tmp;
    time = time + tmp/60;
    cin >> age >> classification;

    v.push_back(make_tuple(
      getPrioFight(fight),
      getPrioHour(time),
      0 - age,
      classification,
      i
    ));
  }

  sort(v.begin(), v.end());


  for(int i = 0; i < v.size() && i < spots; i++){
    cout << get<4>(v[i]) << "\n";
  }

}