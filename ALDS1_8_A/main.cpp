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

struct node
{
  int   key;
  node* parent;
  node* left;
  node* right;
};

node* NIL;

void insert(node*& root, int n) {
  // 挿入する値
  node* newNode;
  newNode        = (node*)malloc(sizeof(node));
  newNode->key   = n;
  newNode->left  = NIL;
  newNode->right = NIL;

  if (root == NIL) {
    root = newNode;
    return;
  }

  node* parentNodeToInsert = NIL;
  node* current            = root;
  // z を挿入するべき場所を探す
  while (current != NIL) {
    parentNodeToInsert = current;
    if (newNode->key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  newNode->parent = parentNodeToInsert;
  if (newNode->key < parentNodeToInsert->key) {
    parentNodeToInsert->left = newNode;
  } else {
    parentNodeToInsert->right = newNode;
  }
}

void inorder(node* u) {
  if (u == NIL) return;
  inorder(u->left);
  cout << " " << u->key;
  inorder(u->right);
}

void preorder(node* u) {
  if (u == NIL) return;
  cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
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
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
  }
}
