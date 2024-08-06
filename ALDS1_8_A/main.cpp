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

class node
{
private:
  node* NIL;

  int   key;
  node* parent;
  node* left;
  node* right;

public:
  node() : parent(NIL), left(NIL), right(NIL) {}
  node(int key) : node() { this->key = key; }

  ~node() {}

  void insert(int n) {
    // 挿入する値
    node* newNode;
    newNode        = (node*)malloc(sizeof(node));
    newNode->key   = n;
    newNode->left  = NIL;
    newNode->right = NIL;

    // if (this == NIL) {
    //   return;
    // }

    node* parentNodeToInsert = NIL;
    node* current            = this;
    // newNode を挿入するべき場所を探す
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

  void inorder() {
    if (this == NIL) return;
    this->left->inorder();
    cout << " " << this->key;
    this->right->inorder();
  }

  void preorder() {
    if (this == NIL) return;
    cout << " " << this->key;
    this->left->preorder();
    this->right->preorder();
  }
};


int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  const cinp(int, num);
  node root;
  rep(i, num) {
    const cinp(string, cmd);
    if (cmd == "insert") {
      const cinp(int, key);
      root.insert(key);
    } else {
      root.inorder();
      cout << endl;
      root.preorder();
      cout << endl;
    }
  }
}
