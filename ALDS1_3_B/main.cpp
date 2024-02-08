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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int                        n, quantum;
  deque<tuple<string, int> > processes;
  cin >> n >> quantum;
  rep(i, n) {
    string process;
    int    time_left;
    cin >> process >> time_left;
    processes.push_back(make_tuple(process, time_left));
  }

  // キューに頭から値をpush_backしていく
  // tupleの配列とする

  // time = 0
  // while キューが空出ない間
  // 先頭要素を読み取る
  // time += min(残り時間, quantum)
  // 残り時間 -= quantum
  // 残り時間 <= 0 のとき、print
  // そうでなければ push_back
  // pop_front
  // while ここまで

  int time = 0;
  while (! processes.empty()) {
    tuple<string, int> front = processes.front();
    time += min(get<1>(front), quantum);
    get<1>(front) -= quantum;
    if (get<1>(front) <= 0) {
      cout << get<0>(front) << " " << time << endl;
    } else {
      processes.push_back(front);
    }
    processes.pop_front();
  }
}
