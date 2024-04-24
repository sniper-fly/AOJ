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
  int depth;
  int height;
};

constexpr int NIL = -1;

void print(const map<int, Node>& tree) {
  for (auto i = tree.begin(); i != tree.end(); ++i) {
    const int    id     = i->first;
    const Node&  node   = i->second;
    const int    degree = (node.left != NIL) + (node.right != NIL);
    const string type   = [&node]() {
      if (node.parent == NIL) {
        return "root";
      } else if (node.left == NIL && node.right == NIL) {
        return "leaf";
      } else {
        return "internal node";
      }
    }();
    const int sibling = [&]() {
      if (node.parent == NIL) return -1;

      const int left_sib  = tree.at(node.parent).left;
      const int right_sib = tree.at(node.parent).right;
      return id == left_sib ? right_sib : left_sib;
    }();

    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, "
           "height = %d, %s\n",
        id, node.parent, sibling, degree, node.depth, node.height,
        type.c_str());
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  const cinp(int, len);
  map<int, Node> tree;
  rep(i, len) {
    const cinp(int, id);
    const cinp(int, left);
    const cinp(int, right);
    // もし初出の値であれば、parentをNILに設定する
    if (tree.find(id) == tree.end()) tree[id].parent = NIL;
    tree[id].left  = left;
    tree[id].right = right;
    if (left != NIL) tree[left].parent = id;
    if (right != NIL) tree[right].parent = id;
  }

  int root_id;
  for (auto i = tree.begin(); i != tree.end(); ++i) {
    if (tree[i->first].parent == NIL) root_id = i->first;
  }

  function<int(int, int)> rec_height = [&tree, &rec_height](
                                           int id, int height) {
    if (tree[id].left == NIL && tree[id].right == NIL) return height;
    const int left  = tree[id].left;
    const int right = tree[id].right;
    return max(left == NIL ? height : rec_height(left, height + 1),
        right == NIL ? height : rec_height(right, height + 1));
  };

  // depth の情報を付与する
  // 0 から len - 1 までの番号なのでこれで問題なし
  function<void(int, int)> rec_depth = [&](int id, int depth) {
    if (id == -1) return;
    tree[id].depth  = depth;
    tree[id].height = rec_height(id, 0);
    rec_depth(tree[id].left, depth + 1);
    rec_depth(tree[id].right, depth + 1);
  };
  rec_depth(root_id, 0);

  print(tree);
}
