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
void swap(int& l, int& r) {
  const int tmp = l;
  l             = r;
  r             = tmp;
}

int partition(int nums[], int first, int last) {
  const int criteria    = nums[last];
  int       first_large = first;
  for (int current = first; current < last; ++current) {
    if (nums[current] <= criteria) {
      swap(nums[first_large], nums[current]);
      ++first_large;
    }
  }
  swap(nums[first_large], nums[last]);
  return first_large;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int nums[100000], len;

  cin >> len;
  rep(i, len) { cin >> nums[i]; }

  const int q = partition(nums, 0, len - 1);
  rep(i, len) {
    if (i != 0) cout << " ";
    if (i == q) {
      cout << "[" << nums[i] << "]";
    } else {
      cout << nums[i];
    }
  }
  cout << endl;
}
