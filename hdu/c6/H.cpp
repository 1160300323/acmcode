#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const ll INF = 4e18;
const double EPS = 1e-9;

int T;
ll n, k, m;
bool check(ll n, ll del) {
	ll cnt = 0;
	for (ll i = 1; i <= del; ++i) {
		if (__gcd(n, n + i) == 1) {
			++cnt;
		}
	}
	return cnt == m && __gcd(n, n + del) == 1;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &k, &m);
		ll ans = INF;
		for (ll del = 1; del <= 1000; ++del) {
			n = k ^ del;
			if (check(n, del)) {
				ans = min(ans, n);
			}
		}
		printf("%lld\n", INF == ans ? -1 : ans);
	}
	return 0;
}
