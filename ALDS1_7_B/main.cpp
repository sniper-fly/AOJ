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
    const int id     = i->first;
    const int parent = i->second.parent;
    // const int sib
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int len;
  cin >> len;
  map<int, Node> tree;
  rep(i, len) {
    int id, left, right;
    cin >> id >> left >> right;
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
    if (tree[id].left == NIL || tree[id].right == NIL) return height;
    return max(rec_height(tree[id].left, height + 1),
        rec_height(tree[id].right, height + 1));
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
