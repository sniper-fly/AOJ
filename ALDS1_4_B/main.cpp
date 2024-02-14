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

const int NOT_FOUND = -1;

int liner_search(int nums[], int last_idx, int key) {
  int left  = 0;
  int right = last_idx;
  while (left < right) {
    const int mid = (left + right) / 2;
    if (nums[mid] == key) {
      return mid;
    } else if (nums[mid] > key) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return NOT_FOUND; // 見つからなかったら
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int n, q, nnums[100000];
  cin >> n;
  rep(i, n) { cin >> nnums[i]; }

  int count = 0;
  cin >> q;
  rep(i, q) {
    int qnum;
    cin >> qnum;

    if (liner_search(nnums, n, qnum) != NOT_FOUND) {
      ++count;
    }
  }
  cout << count << endl;
}
