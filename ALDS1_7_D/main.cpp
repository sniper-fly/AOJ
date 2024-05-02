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
  vector<int> inorder_history;
  rep(i, len) {
    const cinp(int, id);
    inorder.push_back(id);
    inorder_history.push_back(id);
  }


  map<int, Node> tree;
  // 3 2 5 4 6 1 8 7 9 を例に考える
  int i = 0;
  int left_child;
  int right_child;

  const int pre = preorder[i];
  // pre を inorder 内から探して、preを根として左部分木と右部分木に分ける
  auto current_root_itr = find(inorder.begin(), inorder.end(), pre);
  auto left_end         = current_root_itr - 1;
  auto right_start      = current_root_itr + 1;
  int  id               = *current_root_itr;
  *current_root_itr     = NIL;
  if (tree.find(id) == tree.end()) tree[id].parent = NIL;


  auto next_root_itr = find(inorder.begin(), left_end, preorder[i + 1]);
  left_end           = next_root_itr - 1;
  right_start        = next_root_itr + 1;
  *next_root_itr     = NIL;
  if (*left_end == NIL || left_end < inorder.begin()) {
    cout << "shuryo";
  }

  next_root_itr  = find(inorder.begin(), left_end, preorder[i + 2]);
  left_end       = next_root_itr - 1;
  right_start    = next_root_itr + 1;
  id             = *next_root_itr;
  *next_root_itr = NIL;
  if (*left_end != NIL && left_end >= inorder.begin()) {
    left_child              = 0; // saiki
    tree[id].left           = left_child;
    tree[left_child].parent = id;
  }
  if (*right_start != NIL && right_start < inorder.end()) {
    right_child              = 0; // saiki
    tree[id].left            = right_child;
    tree[right_child].parent = id;
  }
  // 左端(葉)に到達
  cout << "return: " << id << endl;

  auto current_preorder = preorder.begin();
  function<int(vector<int>::iterator, vector<int>::iterator, int)> tree_gen =
      [&](vector<int>::iterator left_start, vector<int>::iterator right_end,
          int search_id) -> int {
    const auto next_root_itr = find(left_start, right_end, search_id);
    const auto left_end      = next_root_itr - 1;
    const auto right_start   = next_root_itr + 1;
    const int  id            = *next_root_itr;

    *next_root_itr = NIL;

    // preorderでどこまでたどっているのか、再帰の親含め全体で共有できるグローバルな変数が必要になってしまう
    // クロージャーでなんとかする

    if (*left_end != NIL && left_end >= inorder.begin()) {
      const int left_child    = tree_gen(left_start, left_end, 9999); // saiki
      tree[id].left           = left_child;
      tree[left_child].parent = id;
    }
    if (*right_start != NIL && right_start < inorder.end()) {
      const int right_child = tree_gen(right_start, right_end, 9999); // saiki
      tree[id].right        = right_child;
      tree[right_child].parent = id;
    }
    return id;
  };
}
