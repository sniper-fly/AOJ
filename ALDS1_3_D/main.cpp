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

typedef struct
{
  int left_i;
  int current_sum;
} pond_info;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  stack<int>        left_slopes;
  vector<pond_info> each_pond;
  char              ch;
  int               sum = 0;
  for (int i = 0; cin >> ch; ++i) {
    if (ch == '\\') {
      left_slopes.push(i);
    } else if (ch == '/' && left_slopes.size() > 0) {
      const int left_i = left_slopes.top();
      left_slopes.pop();

      const int current_diff = i - left_i;
      sum += current_diff;

      int sum_of_each_pond = current_diff;
      // 個別の水たまりの左端が、現在のidxに対応する左坂のidxより大きい限り
      while (each_pond.size() > 0 && each_pond.back().left_i > left_i) {
        sum_of_each_pond += each_pond.back().current_sum;
        each_pond.pop_back();
      }
      each_pond.push_back({ left_i, sum_of_each_pond });
    }
  }

  cout << sum << endl;
  cout << each_pond.size();
  for (pond_info e : each_pond) {
    cout << " " << e.current_sum;
  }
  cout << endl;
}
