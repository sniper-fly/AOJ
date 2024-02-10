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

  int       n;
  list<int> elements;
  cin >> n;
  rep(i, n) {
    string command;
    int    key;
    cin >> command;

    if (command == "insert") {
      cin >> key;
      elements.push_front(key);
    } else if (command == "delete") {
      cin >> key;
      for (auto it = elements.begin(); it != elements.end(); ++it) {
        if (*it == key) {
          elements.erase(it);
          break;
        }
      }
    } else if (command == "deleteFirst") {
      elements.pop_front();
    } else if (command == "deleteLast") {
      elements.pop_back();
    }
  }

  int is_not_first = 0;
  for (auto& e : elements) {
    if (is_not_first++)
      cout << " ";
    cout << e;
  }
  cout << endl;
}
