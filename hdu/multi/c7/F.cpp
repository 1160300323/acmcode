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
ll cal(ll x) {
	return (m / (x - k + 1) + 1) * x;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld%lld", &n, &m, &k);
		ll ans = 4e18;
		ll ans1 = cal(n);
		ll ans2 = cal(k);
		const int d = 6000;
		for (ll i = k; i <= min(k + d, n); ++i) {
			ll tmp_ans = cal(i);
			ans = min(ans, tmp_ans);
		}
		ll nn = m / (m / (n - k + 1) + 1) + 1;
		for (ll i = nn; i >= max(k, nn - d); --i) {
			ll tmp_ans = cal(i);
			ans = min(ans, tmp_ans);
		}
		ll x = floor(sqrt(m * (k - 1))) + k - 1;
		if (x == k - 1) x = k;
		x = m / (m / (x - k + 1) + 1) + 1;
		for (ll i = max(k, x - d); i <= min(n, x + d); ++i) {
			ll tmp_ans = cal(i);
			ans = min(ans, tmp_ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
