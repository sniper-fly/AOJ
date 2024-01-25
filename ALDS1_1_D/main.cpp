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
static const int MAX = 200000;

int main() {
  int prices[MAX], n;

  cin >> n;
  rep(i, n) { cin >> prices[i]; }

  // init value
  int max_diff = prices[1] - prices[0];
  int minv     = prices[0];
  for (ll i = 1; i < n; ++i) {
    max_diff = max(prices[i] - minv, max_diff);
    minv     = min(prices[i], minv);
  }

  // rep(i, n) {
  //   for (ll j = i + 1; j < n; ++j) {
  //     const ll diff = prices[j] - prices[i];
  //     if (diff > max_diff) {
  //       max_diff = diff;
  //     }
  //   }
  // }
  cout << max_diff << endl;
}
