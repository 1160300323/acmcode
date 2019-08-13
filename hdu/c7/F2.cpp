#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int t;
ll n, m, k;
ll cal(ll x)
{
  return (m / x + 1) * (x + k - 1);
}
int main()
{
  scanf("%d", &t);
  while (t--)
  {
    scanf("%lld%lld%lld", &n, &m, &k);
    if (m == 0)
    {
      printf("%d\n", k);
      continue;
    }
    if (k == 1)
    {
      printf("%d\n", m + 1);
      continue;
    }
    ll ans1 = cal(n - k + 1);
    ll ans2 = cal(1);
    ll ans3 = 4e18;
    ll ans4 = 4e18;
    const int d = 2000;
    long long ans = min(ans1, ans2);
    for (int i = 0; i <= d; i++)
    {
      if (m > i && m / (m - i) + 1 >= 1 && m / (m - i) + 1 <= n - k + 1)
        ans = min(ans, cal(m / (m - i) + 1));
    }
    for (int i = 1; i <= d; i++)
    {
      if (m / (m / (n - k + 1) + i) + 1 >= 1 && m / (m / (n - k + 1) + i) + 1 <= n - k + 1)
        ans = min(ans, cal(m / (m / (n - k + i) + 1) + 1));
    }
    ll x = floor(sqrt(m * (k - 1)));
    if (1 <= x && x <= n - k + 1)
    {
      ans3 = cal(x);
    }
    if (1 <= x + 1 && x + 1 <= n - k + 1)
    {
      ans4 = cal(x + 1);
    }
    if (x != 0)
    {
      for (int i = 1; i <= d; i++)
      {
        if (1 <= m / (m / x + i) + 1 && m / (m / x + i) + 1 <= n - k + 1)
        {
          ans = min(ans, cal(m / (m / x + i) + 1));
        }
      }
      for (int i = 0; i <= d; i++)
        if (m / x - i > 0)
        {
          if (1 <= m / (m / x - i) + 1 && m / (m / x - i) + 1 <= n - k + 1)
          {
            ans = min(ans, cal(m / (m / x - i) + 1));
          }
        }
    }
    ans = min(ans, min(ans3, ans4));
    printf("%lld\n", ans);
  }
  return 0;
}
