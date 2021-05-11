#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

struct gg {
	ll p, q;
	gg () {}
	gg (ll p, ll q) : p(p), q(q) {}
	gg ini() {
		ll g = __gcd(p, q);
		return gg(p / g, q / g);
	}
	gg operator + (const gg &g) const {
		ll tp = p * g.p;
		ll tq = q * g.p + p * g.q;
		return gg(tp, tq).ini();
	}
	gg operator - (const gg &g) const {
		ll tp = p * g.p;
		ll tq = q * g.p - p * g.q;
		return gg(tp, tq).ini();
	}
	gg operator / (const ll &d) const {
		return gg(p * d, q).ini();
	}
	gg operator * (const ll &d) const {
		return gg(p, q * d).ini();
	}
	gg operator | (const gg &g) const {
		return gg(p * g.p, q * g.q).ini();
	}
	void out() {
		if (p < 0) p = -p, q = -q;
		if (1 == p) printf("%lld\n", q);
		else printf("%lld/%lld\n", q, p);
	}
} g[10015];
int n, m, a[10015];
int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			g[i] = gg(m, a[i]).ini();
		}
		gg res = gg(1, 1);
		for (int i = 1; i <= n; ++i) {
			res = res - g[i];
		}
		res = res / n;
		gg ans = (res | res) * n;
		ans.out();
	}
	return 0;
}
