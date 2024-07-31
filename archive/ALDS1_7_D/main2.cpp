#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ld  = long double;
using pll = pair<ll, ll>;
#define rep(i, n)       for (ll i = 0; i < n; ++i)
#define all(c)          begin(c), end(c)
#define PI              acos(-1)
#define oo              2e18
#define cinp(type, var) type var = c_input<type>()
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
template<typename T>
T c_input() {
  T input;
  cin >> input;
  return input;
}
// priority_queue<ll, vector<ll>, greater<ll>> Q;
// LMAX = 18446744073709551615 (1.8*10^19)
// IMAX = 2147483647 (2.1*10^9)
/*

*/
struct Node
{
  int left;
  int right;
  int parent;
};

constexpr int NIL = -1;

void reconstruct_tree(
    vector<int>& preorder, vector<int>& inorder, vector<int>& postorder) {
  int idx = 0;

  function<void(vector<int>::iterator, vector<int>::iterator)> rec =
      [&](vector<int>::iterator left, vector<int>::iterator right) {
        if (left >= right) return;
        const int                   next = preorder.at(idx++);
        const vector<int>::iterator root = find(all(inorder), next);
        rec(left, root);
        rec(root + 1, right);
        postorder.push_back(next);
      };
  rec(inorder.begin(), inorder.end());
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  const cinp(int, len);
  vector<int> preorder;
  rep(i, len) {
    const cinp(int, id);
    preorder.push_back(id);
  }

  vector<int> inorder;
  rep(i, len) {
    const cinp(int, id);
    inorder.push_back(id);
  }

  vector<int> postorder;
  reconstruct_tree(preorder, inorder, postorder);
}
