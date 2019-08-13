#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;

int n, x[200015], y[200015], a[200015], b[200015];
int cnta, cntb;
ll ans;
map<int, int> mmpx, mmpy;
struct gg {
	int x, y;
	gg () {}
	gg (int x, int y) : x(x), y(y) {}
	bool operator < (const gg &g) const {
		return y == g.y ? x > g.x : y > g.y;
	}
} g[200015];
int c[200015], f[200015];
vector<int> pos[200015];
int lb(int x) {return x & -x;}
void add(int p, int x) {
	for (; p <= cnta; p += lb(p)) {
		c[p] += x;
	}
}
int query(int p) {
	int res = 0;
	for (; p; p -= lb(p)) res += c[p];
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		mmpx[x[i]]; mmpy[y[i]];
	}
	for (map<int, int>::iterator it = mmpx.begin(); it != mmpx.end(); ++it) {
		it -> second = ++cnta;
	}
	for (map<int, int>::iterator it = mmpy.begin(); it != mmpy.end(); ++it) {
		it -> second = ++cntb;
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = mmpx[x[i]], b[i] = mmpy[y[i]];
		g[i] = gg(a[i], b[i]);
		pos[b[i]].pb(a[i]);
	}
	for (int i = 1; i <= cntb; ++i) {
		pos[i].pb(0);
		sort(pos[i].begin(), pos[i].end());
	}
	sort(g + 1, g + n + 1);
	for (int i = 1; i <= n; ++i) {
		int a = g[i].x, b = g[i].y;
		if (!f[a]) {
			f[a] = 1;
			add(a, 1);
		}
		int p = lower_bound(pos[b].begin(), pos[b].end(), a) - pos[b].begin() - 1;
		int a2i = pos[b][p];
		//cout << a2i << ' ' << a << ' ' << cnta << endl;
		ll c1 = query(a) - query(a2i);
		ll c2 = query(cnta) - query(a - 1);
		ans += c1 * c2;
		//cout << c1 << ' ' << c2 << endl;
	}
	printf("%lld\n", ans);
	return 0;
}
