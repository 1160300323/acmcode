#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int n, m, l;
struct gg {
	int x; int id;
	gg () {}
	gg (int x, int id) : x(x), id(id) {}
	bool operator < (const gg &g) const {
		return x < g.x;
	}
} g[200015];
int a[200015], b[200015];
int c[200015], ans[200015];
int main() {
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &g[i].x);
		g[i].id = i;
	}
	sort(g + 1, g + m + 1);
	for (int i = 1; i <= n; ++i) {
		if (b[i] > l) continue;
		int delx = l - b[i];
		int x1 = a[i] - delx;
		int x2 = a[i] + delx;
		int p1 = lower_bound(g + 1, g + m + 1, gg(x1, 0)) - g;
		int p2 = upper_bound(g + 1, g + m + 1, gg(x2, 0)) - g;
		++c[p1], --c[p2];
	}
	for (int i = 1; i <= m; ++i) {
		c[i] += c[i - 1];
		ans[g[i].id] = c[i];
	}
	for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
	return 0;
}
