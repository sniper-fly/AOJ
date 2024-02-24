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
  string input;
  // エンドラインまでの入力を読み取る
  getline(std::cin, input);

  // std::istringstreamを使って空白区切りの文字列をcinから読み取る
  istringstream iss(input);
  string        symbol;
  vector<int>   num_stack;
  while (iss >> symbol) {
    try {
      int num = stoi(symbol);
      num_stack.push_back(num);
    } catch (const invalid_argument _e) { // 記号の場合はstoiでエラーになる
      int right = num_stack.back();
      num_stack.pop_back();
      int left = num_stack.back();
      num_stack.pop_back();

      if (symbol == "+") {
        num_stack.push_back(left + right);
      } else if (symbol == "-") {
        num_stack.push_back(left - right);
      } else if (symbol == "*") {
        num_stack.push_back(left * right);
      }
    }
  }
  cout << num_stack[0] << endl;
}
