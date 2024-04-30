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


  map<int, Node> tree;
  // 3 2 5 4 6 1 8 7 9 を例に考える
  int       i   = 0;
  const int pre = preorder[i];
  // pre を inorder 内から探して、preを根として左部分木と右部分木に分ける
  const auto current_root_itr = find(inorder.begin(), inorder.end(), pre);
  const int  id               = *current_root_itr;
  if (tree.find(id) == tree.end()) tree[id].parent = NIL;

  auto left_end    = current_root_itr - 1;
  auto right_start = current_root_itr + 1;

  auto next_root_itr = find(inorder.begin(), left_end, preorder[i + 1]);
  left_end           = next_root_itr - 1;
  right_start        = next_root_itr + 1;

  next_root_itr = find(inorder.begin(), left_end, preorder[i + 2]);
  //
}
