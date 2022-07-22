#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll swaps = 0;
void merge_sort(int l, int r, vector<pair<int,int>>& a) {
  if (r - l == 1) { return; }
  
  int mi = l + (r - l) / 2;
  
  merge_sort(l, mi, a); 
  merge_sort(mi, r, a);
  vector<pair<int, int>> aux (r - l);

  int i = l, j = mi;
  for (int k = 0; k < r - l; k++) {
    if (i < mi && j < r) {
    if (!(a[i] < a[j]) && !(a[j].second)) { swaps += mi - i; }
    if (a[i] < a[j]) { aux[k] = a[i++]; }
    else { aux[k] = a[j++]; }
    } else if (i < mi) { aux[k] = a[i++]; }
    else { aux[k] = a[j++]; }
  }

  copy(aux.begin(), aux.end(), a.begin()+l);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, h, tmp;
  cin >> n >> h;
  vector<pair<int,int>> a(n);
  for(int i = 0; i < n; i++, h--){
    int k = h > 0 ? 1 : 0;
    cin >> tmp;
    a[i] = make_pair(tmp, k);
  }

  merge_sort(0, n, a);

  cout << swaps;
  
}