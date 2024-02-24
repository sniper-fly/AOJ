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

// void insertionSort(ll* numbers, ll n) {
//   print_process(numbers, n);
//   // 2番目の要素から最後の要素まで順に走査する
//   for (ll i = 1; i < n; ++i) {
//     ll v = numbers[i];
//     // 挿入位置のインデックス, 最初は1番目の要素を考える
//     ll j = i - 1;
//     // 挿入位置のnumberが選択中の数字より大きければ、forを続ける
//     for (; j >= 0 && numbers[j] > v; --j) {
//       // 数字の並びを1個ずつ右にずらす
//       numbers[j + 1] = numbers[j];
//     }
//     // j は選択中の数字よりも小さいので、その右隣にvを入れる
//     numbers[j + 1] = v;
//     print_process(numbers, n);
//   }
// }

void insertionSort(ll numbers[], ll n) {
  // 1番目の要素 (v)から、n - 1番目の要素までループさせる
  // v をひとつ左の要素 w
  // と比較して、それより大きければループを終え、現在のidxに代入する
  // 小さければ、wを右に1個ずらし、ループを繰り返す。
  print_process(numbers, n);

  for (ll i = 1; i < n; ++i) {
    ll v = numbers[i];
    ll j = i - 1; // 検査対象の一個隣のidxから探索を始める
    for (; j >= 0 && numbers[j] > v; --j) {
      numbers[j + 1] = numbers[j]; // 1個右にずらす
    }
    numbers[j + 1] = v;
    print_process(numbers, n);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  ll n;
  cin >> n;
  ll numbers[100];
  rep(i, n) { cin >> numbers[i]; }

  insertionSort(numbers, n);
}
