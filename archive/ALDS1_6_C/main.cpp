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

constexpr int MAX      = 500000;
constexpr int SENTINEL = 2000000000;

void merge(int nums[], int len, int left, int mid, int right, int& cnt) {
  int L[MAX / 2 + 2], R[MAX / 2 + 2];

  int n1 = mid - left;
  int n2 = right - mid;

  // 分割した配列の初期化
  rep(i, n1) { L[i] = nums[left + i]; }
  rep(i, n2) { R[i] = nums[mid + i]; }
  L[n1] = R[n2] = SENTINEL;

  for (int i = 0, j = 0, k = left; k < right; ++k, ++cnt) {
    if (L[i] <= R[j]) {
      nums[k] = L[i++];
    } else {
      nums[k] = R[j++];
    }
  }
}

void mergeSort(int nums[], int len, int left, int right, int& cnt) {
  if (left + 1 >= right) return;
  int mid = (left + right) / 2;
  mergeSort(nums, len, left, mid, cnt);
  mergeSort(nums, len, mid, right, cnt);
  merge(nums, len, left, mid, right, cnt);
}

void swap(int& l, int& r) {
  const int tmp = l;
  l             = r;
  r             = tmp;
}

int partition(int nums[], int p, int r) {
  const int criteria = nums[r];
  int       i        = p - 1;
  for (int j = p; j < r; ++j) {
    if (nums[j] <= criteria) {
      ++i;
      swap(nums[i], nums[j]);
    }
  }
  swap(nums[i + 1], nums[r]);
  return i + 1;
}

void quickSort(int nums[], int n, int left, int right) {
  if (left >= right) return;
  const int p = partition(nums, left, right);
  quickSort(nums, n, left, p - 1);
  quickSort(nums, n, p + 1, right);
}

typedef struct
{
  char suit;
  int  num;
} card;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int  n;
  card cards[100000];
  cin >> n;
  rep(i, n) { cin >> cards[i].suit >> cards[i].num; }
}
