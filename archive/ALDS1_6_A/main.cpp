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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  constexpr int VMAX = 10000;
  int           len;

  cin >> len;
  vector<ll> inputs(len + 1), outputs(len + 1), counter(VMAX + 1, 0);

  rep(i, len) {
    cin >> inputs[i + 1];
    counter[inputs[i + 1]]++;
  }

  // 累積和を作成
  for (int i = 1; i <= VMAX; ++i) {
    counter[i] += counter[i - 1];
  }

  for (int i = len; i >= 1; --i) {
    const ll num_to_sort = inputs[i];
    const ll insert_idx =
        counter[num_to_sort]--; // 同じ数が複数存在する場合の調整でデクリメント
    outputs[insert_idx] = num_to_sort;
  }

  for (int i = 1; i <= len; ++i) {
    if (i > 1) cout << " ";
    cout << outputs[i];
  }
  cout << endl;
}
