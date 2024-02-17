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

constexpr int primers[16] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
  43, 47, 49 };
constexpr int dict_l      = 1000000;

// ll calcKey(const string& kwd) {
//   ll sum = 0;
//   rep(i, kwd.length()) {
//     switch (kwd[i]) {
//       case 'A':
//         sum += primers[i] * primers[12];
//         break;
//       case 'C':
//         sum += primers[i] * primers[13];
//         break;
//       case 'G':
//         sum += primers[i] * primers[14];
//         break;
//       case 'T':
//         sum += primers[i] * primers[15];
//         break;
//     }
//   }
//   return sum;
// }


ll calcKey(const string& kwd) {
  auto getChar = [](char ch) {
    if (ch == 'A')
      return 1;
    else if (ch == 'C')
      return 2;
    else if (ch == 'G')
      return 3;
    else
      return 4;
  };

  ll sum = 0, p = 1;
  for (ll i = 0; i < kwd.length(); ++i) {
    sum += p * (getChar(kwd[i]));
    p *= 5;
  }
  return sum;
}

int calcHash(ll key, int i) {
  auto h1 = [](ll key) { return key % dict_l; };
  auto h2 = [](ll key) { return 1 + (key % (dict_l - 1)); };

  return (h1(key) + i * h2(key)) % dict_l;
}

int insert(vector<string>& dict, string kwd) {
  const ll key = calcKey(kwd);
  for (int i = 0;; ++i) {
    const int j = calcHash(key, i);
    if (dict[j].empty()) {
      dict[j] = kwd;
      return j;
    }
  }
}

int search(const vector<string>& dict, string kwd) {
  const ll key = calcKey(kwd);
  for (int i = 0;; ++i) {
    const int j = calcHash(key, i);
    if (dict[j] == kwd) {
      return j;
    } else if (dict[j].empty() || i >= dict_l) {
      return -1;
    }
  }
}

void zeroume(char cmd_buf[8], char kwd_buf[13]) {
  rep(i, 8) { cmd_buf[i] = '\0'; }
  rep(i, 13) { kwd_buf[i] = '\0'; }
}


int main() {
  // cin.tie(0);
  // ios::sync_with_stdio(0);
  // cout << fixed << setprecision(10);

  vector<string> dict(dict_l);

  int n;
  // cin >> n;
  scanf("%d", &n);

  char cmd_buf[8];
  char kwd_buf[13];
  rep(i, n) {
    zeroume(cmd_buf, kwd_buf);
    scanf("%s %s", cmd_buf, kwd_buf);

    string cmd(cmd_buf);
    string kwd(kwd_buf);
    if (cmd == "insert") {
      insert(dict, kwd);
    } else if (cmd == "find") {
      if (search(dict, kwd) != -1) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
}
