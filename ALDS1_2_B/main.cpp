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

void swap(ll& a, ll& b) {
  ll tmp = a;
  a      = b;
  b      = tmp;
}

void print_process(ll* numbers, ll n) {
  cout << numbers[0];
  rep(i, n - 1) { cout << " " << numbers[i + 1]; }
  cout << endl;
}

ll selection_sort(ll numbers[], ll n) {
  ll swap_count = 0;
  rep(i, n) {
    ll min_idx = i;
    for (ll j = i; j < n; ++j) {
      if (numbers[j] < numbers[min_idx]) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      swap(numbers[i], numbers[min_idx]);
      ++swap_count;
    }
  }
  return swap_count;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  ll n, numbers[100];
  cin >> n;
  rep(i, n) { cin >> numbers[i]; }
  ll count = selection_sort(numbers, n);
  print_process(numbers, n);
  cout << count << endl;
}
