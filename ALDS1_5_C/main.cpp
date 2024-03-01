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

struct Point
{
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  double x, y;
};

void koch(const int depth, const Point& l, const Point& r) {
  if (depth == 0)
    return;

  Point        s, t, u;
  const double th = M_PI / 3;

  s.x = (2.0 * l.x + 1.0 * r.x) / 3.0;
  s.y = (2.0 * l.y + 1.0 * r.y) / 3.0;
  t.x = (1.0 * l.x + 2.0 * r.x) / 3.0;
  t.y = (1.0 * l.y + 2.0 * r.y) / 3.0;
  u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
  u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

  koch(depth - 1, l, s);
  printf("%.8f %.8f\n", s.x, s.y);
  koch(depth - 1, s, u);
  printf("%.8f %.8f\n", u.x, u.y);
  koch(depth - 1, u, t);
  printf("%.8f %.8f\n", t.x, t.y);
  koch(depth - 1, t, r);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int         depth;
  const Point l { 0, 0 }, r { 100, 0 };

  scanf("%d", &depth);

  printf("%.8f %.8f\n", l.x, l.y);
  koch(depth, l, r);
  printf("%.8f %.8f\n", r.x, r.y);

  return 0;
}
