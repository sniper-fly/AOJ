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

constexpr int VMAX = 10000;

int solve(int len, const vector<int>& nums, int min_all) {
  int          ans = 0;
  vector<int>  dest(nums.begin(), nums.end());
  vector<int>  T(VMAX + 1);
  vector<bool> V(len, false);

  // まず、ソート後の目標とする配列を用意する
  sort(dest.begin(), dest.begin() + len);

  rep(i, len) { T[dest[i]] = i; }
  rep(i, len) {
    if (V[i]) continue;
    int cur          = i;
    int sum          = 0;
    int min_in_cycle = VMAX;
    int cycle_len    = 0;
    while (true) {
      V[cur] = true;
      ++cycle_len;
      const int v  = nums[cur];
      min_in_cycle = min(min_in_cycle, v);
      sum += v;
      cur = T[v];
      if (V[cur]) break;
    }
    // サイクル内の要素での最小コスト vs サイクル外の最小値を借りた場合のコスト
    ans += min(sum + (cycle_len - 2) * min_in_cycle,
        sum + min_in_cycle + (cycle_len + 1) * min_all);
  }

  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int len;
  int min_all = VMAX;
  cin >> len;
  vector<int> nums(len);
  rep(i, len) {
    cin >> nums[i];
    min_all = min(min_all, nums[i]);
  }
  int ans = solve(len, nums, min_all);
  cout << ans << endl;
}
