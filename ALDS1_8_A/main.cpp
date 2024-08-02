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

typedef struct
{
  int   key;
  node *parent, *left, *right;
} node;

node* NIL;

void insert(node* root, int n) {
  node* y       = NIL;
  node* current = root;
  node* z;

  // 挿入する値
  z        = (node*)malloc(sizeof(node));
  z->key   = n;
  z->left  = NIL;
  z->right = NIL;

  while (current != NIL) {
    y = current;
    if (z->key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  z->parent = y;
  if (y == NIL) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  const cinp(int, num);
  node* root = NIL;
  rep(i, num) {
    const cinp(string, cmd);
    if (cmd == "insert") {
      const cinp(int, key);
      insert(root, key);
    } else {
      // print
    }
  }
}
