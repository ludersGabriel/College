#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ld getRatio(vector<ll>& arr){
  ld ratio1 = (ld) arr[1] / arr[0];
  ld ratio2 = (ld) arr[2] / arr[1];
  ld ratio3 = (ld) arr[3] / arr[2];

  if(ratio1 == ratio2) return ratio2;
  if(ratio2 == ratio3) return ratio3;
  return ratio1;
}


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;
  vector<ll> nums (n);

  for(auto& el : nums){
    cin >> el;
  }

  sort(nums.begin(), nums.end());

  ld ratio = getRatio(nums);

  for(int i = 0; i < nums.size() - 1; i++){
    if(nums[i] * ratio != nums[i + 1]){
      cout << (ll) (nums[i] * ratio);
      return 0;
    }
  }

  if(ratio != 1 && nums[0] != 1 && nums[0] / ratio == (ll) (nums[0] / ratio)){
    cout << (ll) (nums[0] / ratio) << '\n';
  }

  cout << (ll) (nums[nums.size() - 1] * ratio);

}