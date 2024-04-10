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

// myid jisuu c1 c2... ck

struct Node
{
  int parent;
  int left;
  int right;
  int depth;
};

constexpr int NIL = -1;

void print(int u, const vector<Node>& tree) {
  cout << "node " << u << ": ";
  cout << "parent = " << tree[u].parent << ", ";
  cout << "depth = " << tree[u].depth << ", ";

  if (tree[u].parent == NIL)
    cout << "root, ";
  else if (tree[u].left == NIL)
    cout << "leaf, ";
  else
    cout << "internal node, ";

  cout << "[";

  for (int i = 0, c = tree[u].left; c != NIL; ++i, c = tree[c].right) {
    if (i) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

void rec(int u, int d, vector<Node>& tree) {
  function<void(int, int)> f = [&](int id, int depth) {
    // 終了条件は、right, leftがともにNIL
    tree[id].depth = depth;
    // 兄弟には同じ深さを設定する
    if (tree[id].right != NIL) f(tree[id].right, depth);
    // 子供には深さ+1する
    if (tree[id].left != NIL) f(tree[id].left, depth + 1);
  };
  f(u, d);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int dimension, id, child, sibling, root, len;
  cin >> len;
  vector<Node> tree(len, { NIL, NIL, NIL });
  rep(i, len) {
    cin >> id >> dimension;
    rep(j, dimension) {
      // 各ノードの子を逐次入力する
      cin >> child;
      // 1回目はtree[id]ノードの子としてchildを設定する
      if (j == 0)
        tree[id].left = child;
      else // 2回目以降は
        tree[sibling].right = child;
      // 2回目以降の入力で使う。
      sibling = child;
      // 逐次入力されたノードの親は全てtree[id]
      tree[child].parent = id;
    }
  }
  rep(i, len) {
    if (tree[i].parent == NIL) root = i;
  }

  rec(root, 0, tree);

  rep(i, len) { print(i, tree); }
}
