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

void insertion_sort(ll nums[], ll n, ll gap, ll& cnt) {
  for (ll i = gap; i < n; ++i) {
    ll v = nums[i];
    ll j = i - gap;
    for (; j >= 0 && nums[j] > v; j -= gap, ++cnt) {
      nums[j + gap] = nums[j];
    }
    nums[j + gap] = v;
  }
}

void shell_sort(ll nums[], ll n, ll& cnt, vector<ll>& gaps) {
  for (ll gap = 1; gap <= n; gap = 3 * gap + 1) {
    gaps.push_back(gap);
  }
  for (auto i = gaps.rbegin(), e = gaps.rend(); i != e; ++i) {
    insertion_sort(nums, n, *i, cnt);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  ll n, nums[1000000];
  cin >> n;
  rep(i, n) { cin >> nums[i]; }

  ll         cnt = 0;
  vector<ll> gaps;

  shell_sort(nums, n, cnt, gaps);

  cout << gaps.size() << endl;
  cout << gaps[gaps.size() - 1];
  for (ll i = gaps.size() - 2; i >= 0; --i) {
    cout << " " << gaps[i];
  }
  cout << endl;

  cout << cnt << endl;

  rep(i, n) { cout << nums[i] << endl; }
}
