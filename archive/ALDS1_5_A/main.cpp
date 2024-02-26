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

bool judge(int idx, int nums[], int num_len, int qnum) {
  if (qnum == 0) {
    return true;
  } else if (idx >= num_len || qnum < 0) {
    return false;
  }
  return judge(idx + 1, nums, num_len, qnum) ||
         judge(idx + 1, nums, num_len, qnum - nums[idx]);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int n, nnums[20], q, qnum;
  cin >> n;
  rep(i, n) { cin >> nnums[i]; }
  cin >> q;
  rep(i, q) {
    cin >> qnum;

    if (judge(0, nnums, n, qnum)) { // nnums を使って qnum が作れるかどうか
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
