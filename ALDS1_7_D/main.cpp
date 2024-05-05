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

void calc_postorder(
    vector<int>& order, const map<int, Node>& tree, int root_id) {
  function<void(int)> sub_fn = [&](int id) {
    if (id != NIL && tree.at(id).left != NIL) sub_fn(tree.at(id).left);
    if (id != NIL && tree.at(id).right != NIL) sub_fn(tree.at(id).right);
    order.push_back(id);
  };
  sub_fn(root_id);
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
  vector<int> inorder_history;
  rep(i, len) {
    const cinp(int, id);
    inorder.push_back(id);
    inorder_history.push_back(id);
  }

  map<int, Node> tree;

  // クロージャ変数
  auto current_preorder = preorder.begin();
  function<int(vector<int>::iterator, vector<int>::iterator)> tree_gen =
      [&](vector<int>::iterator left_start,
          vector<int>::iterator right_end) -> int {
    const auto next_root_itr = find(left_start, right_end, *current_preorder);
    const auto left_end      = next_root_itr - 1;
    const auto right_start   = next_root_itr + 1;
    const int  id            = *next_root_itr;

    *next_root_itr = NIL;

    // 左の木が探索済みでない && 木の端より右側である
    if (*left_end != NIL && left_end >= inorder.begin()) {
      ++current_preorder;
      const int left_child = tree_gen(left_start, left_end); // saiki
      if (tree.find(id) == tree.end()) tree[id] = { NIL, NIL, NIL };
      if (tree.find(left_child) == tree.end())
        tree[left_child] = { NIL, NIL, NIL };
      tree[id].left           = left_child;
      tree[left_child].parent = id;
    }

    if (*right_start != NIL && right_start < inorder.end()) {
      ++current_preorder;
      const int right_child = tree_gen(right_start, right_end); // saiki
      if (tree.find(id) == tree.end()) tree[id] = { NIL, NIL, NIL };
      if (tree.find(right_child) == tree.end())
        tree[right_child] = { NIL, NIL, NIL };
      tree[id].right           = right_child;
      tree[right_child].parent = id;
    }
    return id;
  };
  const int id = tree_gen(inorder.begin(), inorder.end());
  if (tree.find(id) == tree.end()) tree[id] = { NIL, NIL, NIL };

  const int root_id = [&]() -> int {
    for (auto it = tree.begin(); it != tree.end(); ++it) {
      if (it->second.parent == NIL) return it->first;
    }
    return NIL;
  }();

  vector<int> postorder;
  calc_postorder(postorder, tree, root_id);
  rep(i, len) {
    if (i) cout << " ";
    cout << postorder[i];
  }
  cout << endl;
}
