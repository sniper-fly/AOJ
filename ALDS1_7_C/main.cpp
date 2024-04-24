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

void calc_preorder(vector<int>& order, const vector<Node>& tree, int root_id) {
  function<void(int)> sub_fn = [&](int id) {
    order.push_back(id);
    if (tree[id].left != NIL) sub_fn(tree[id].left);
    if (tree[id].right != NIL) sub_fn(tree[id].right);
  };
  sub_fn(root_id);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  const cinp(int, len);
  vector<Node> tree(len, { NIL, NIL, NIL });

  rep(i, len) {
    int id, left, right;
    cin >> id >> left >> right;
    tree[id].left  = left;
    tree[id].right = right;
    if (left != NIL) tree[left].parent = id;
    if (right != NIL) tree[right].parent = id;
  }

  const int root_id = [&]() -> int {
    rep(i, len) {
      if (tree[i].parent == NIL) return i;
    }
    return 0;
  }();

  vector<int> preorder;
  calc_preorder(preorder, tree, root_id);
  cout << "Preorder" << endl;
  rep(i, len) {
    if (i) cout << " ";
    cout << preorder[i];
  }
}
