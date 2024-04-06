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

// the map key number is going to be the map value number's index after sorted
int solve(int len, const vector<int>& nums, int min_all) {
  int              ans = 0;
  vector<int>      dest(nums.begin(), nums.end());
  map<int, size_t> dest_idx_of_num;
  vector<bool>     already_searched(len, false);

  // まず、ソート後の目標とする配列を用意する
  sort(dest.begin(), dest.begin() + len);

  // numをキーとし、ソート後の配列がnumを配置するインデックスをvalueとするmap
  rep(i, len) { dest_idx_of_num[dest[i]] = i; }
  rep(i, len) {
    if (already_searched[i]) continue;
    int cur          = i;
    int sum          = 0;
    int min_in_cycle = VMAX;
    int cycle_len    = 0;
    while (true) {
      // numsの配列長と対応したboolの配列で、そのインデックスが探索済みかどうかを保持する
      already_searched[cur] = true;
      ++cycle_len;
      const int w  = nums[cur];
      min_in_cycle = min(min_in_cycle, w);
      sum += w;
      cur = dest_idx_of_num[w];
      if (already_searched[cur]) break;
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
