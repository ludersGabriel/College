#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

#define P 1000000007LL
#define PN cout << "\n"
 
ll power(ll x, ll y,  ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}


ll modInverse(ll a, ll m){
    return power(a, m - 2, m);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, c;
    cin >> n >> c;
    vector<int> offsets (n);
    for (int& x : offsets) cin >> x;
    
    int i, j;
    vector<int> jokers (n, 0);
    for (int k = 0; k < c; k++) {
        cin >> i >> j;
        jokers[j-1] += 1;
    }

    int max = *max_element(offsets.begin(), offsets.end());
    vector<ll> lookup (max + 1, 1);
    for(i = 2; i <= max; i++){
        lookup[i] = (lookup[i - 1] * i) % P;
    }

    ll ret = 1, num, deno;
    for(i = 0; i < n; i++){
        num = lookup[offsets[i]];
        deno = lookup[offsets[i] - n + jokers[i]];

        ret = ((ret * num) % P * modInverse(deno, P)) % P;
    }   

    cout << ret;

}