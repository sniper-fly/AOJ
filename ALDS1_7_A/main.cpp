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
};

constexpr int NIL = -1;

void print(int u, const vector<int>& d, const vector<Node>& tree) {
  cout << "node " << u << ": ";
  cout << "parent = " << tree[u].parent << ", ";
  cout << "depth = " << d[u] << ", ";

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

void rec(int u, int p, vector<int>& d, const vector<Node>& tree) {
  function<void(int, int)> f = [&](int u, int p) {
    d[u] = p;
    if (tree[u].right != NIL) f(tree[u].right, p);
    if (tree[u].left != NIL) f(tree[u].left, p + 1);
  };
  f(u, p);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int depth, id, c, l, r;
  int len;
  cin >> len;
  vector<Node> tree(len, { NIL, NIL, NIL });
  rep(i, len) {
    cin >> id >> depth;
    rep(j, depth) {
      cin >> c;
      if (j == 0)
        tree[id].left = c;
      else
        tree[l].right = c;
      l              = c;
      tree[c].parent = id;
    }
  }
  rep(i, len) {
    if (tree[i].parent == NIL) r = i;
  }

  vector<int> d(len);
  rec(r, 0, d, tree);

  rep(i, len) { print(i, d, tree); }
}
