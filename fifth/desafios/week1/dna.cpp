#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using il = long;

#define DELIMITER "AAAAAAA"

int findFirst(string& code){
  int num = 0;
  for(int i = 0; i < code.length(); i++){
    if(code[i] == 'A'){
      num++;
      for(int j = i + 1; j < code.length() && code[j] == 'A' && num < 7; j++){
        num++;
      }
      if(num == 7) return i;
      else num = 0;
    }
  }

  return -1;
}

int findLast(string& code){
  int num = 0;
  for(int i = code.length() - 1; i >= 0; i--){
    if(code[i] == 'A'){
      num++;
      for(int j = i - 1; j >= 0 && code[j] == 'A' && num < 7; j--){
        num++;
      }
      if(num == 7) return i;
      else num = 0;
    }
  }

  return -1;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll size = 0;
  string code;

  cin >> size >> code;

  ll first = findFirst(code);
  ll last = findLast(code);

  if(first == -1 || last == -1){
    cout << "0";
    return 0;
  } 

  string substr = code.substr(first, last - first + 1);
  cout << substr.length();

}