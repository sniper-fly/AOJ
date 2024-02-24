#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ld  = long double;
using pll = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define all(c)    begin(c), end(c)
#define PI        acos(-1)
#define oo        2e18
template<typename T1, typename T2>
bool chmax(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template<typename T1, typename T2>
bool chmin(T1& a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  } else
    return false;
}
// priority_queue<ll, vector<ll>, greater<ll>> Q;
// LMAX = 18446744073709551615 (1.8*10^19)
// IMAX = 2147483647 (2.1*10^9)
/*

*/

bool check(ll max_w, int loads, int tracks, int weights[]) {
  int i = 0;
  rep(j, tracks) {
    for (ll sum_weights = weights[i]; sum_weights <= max_w;
         sum_weights += weights[++i])
    {
      if (i + 1 == loads)
        return true; // 載せられる
    }
  }
  return false;
}

int solve(int loads, int tracks, int weights[]) {
  ll left  = 0;
  ll right = 100000 * 10000;
  while (right > left) { // right - left が1または0 のとき止まる
    const ll mid = (left + right) / 2;
    if (check(mid, loads, tracks, weights)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return right;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int loads, tracks, weights[100000];

  cin >> loads >> tracks;
  rep(i, loads) { cin >> weights[i]; }
  ll ans = solve(loads, tracks, weights);
  cout << ans << endl;
}
