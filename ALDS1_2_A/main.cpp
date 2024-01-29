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

void print_process(ll* numbers, ll n) {
  cout << numbers[0];
  rep(i, n - 1) { cout << " " << numbers[i + 1]; }
  cout << endl;
}

ll bubbleSort(ll numbers[], ll n) {
  ll   count = 0;
  bool flag  = true;
  while (flag) {
    flag = false;
    for (ll i = n - 1; i >= 1; --i) {
      if (numbers[i - 1] > numbers[i]) {
        flag           = true;
        ll tmp         = numbers[i];
        numbers[i]     = numbers[i - 1];
        numbers[i - 1] = tmp;
        ++count;
      }
    }
  }

  return count;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  ll n, numbers[100];
  cin >> n;
  rep(i, n) { cin >> numbers[i]; }

  ll count = bubbleSort(numbers, n);

  print_process(numbers, n);
  cout << count << endl;
}
