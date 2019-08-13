#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;

int n, deg[1015], R;
int head[1015], nex[2015], tot, to[2015], w[2015];
void add(int u, int v, int ww) {
	nex[++tot] = head[u]; head[u] = tot; to[tot] = v; w[tot] = ww;
	++deg[u];
}
int solve0(int r, int fa, int c) {
	for (int x = head[r]; ~x; x = nex[x]) {
		if (to[x] == fa) continue;
		w[x] -= c;
		return solve0(to[x], r, c);
	}
	return r;
}
struct Fuck {
	int u, v, x;
	Fuck () {}
	Fuck(int u, int v, int x) : u(u), v(v), x(x) {}
};
vector<Fuck> ff;
void solve(int u, int fa) {
	for (int x = head[u], preu = 0, prew; ~x; x = nex[x]) {
		if (to[x] == fa) continue;
		if (preu) {
			int g = solve0(preu, u, prew);
			int h = solve0(to[x], u, prew);
			w[x] -= prew;
			ff.pb(Fuck(g, h, prew + w[x] / 2));
			ff.pb(Fuck(h, R, w[x] / 2));
			ff.pb(Fuck(g, R, -w[x] / 2));
			solve0(to[x], u, w[x]);
			w[x] = 0;
		}
		preu = to[x], prew = w[x];
		solve(to[x], u);
	}
}
int main() {
	scanf("%d", &n);
	clr(head, -1); tot = -1;
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 2) return !printf("NO");
		if (deg[i] == 1) R = i;
	}
	puts("YES");
	ff.pb(Fuck(R, solve0(R, 0, w[head[R]]), w[head[R]]));
	solve(to[head[R]], R);
	printf("%d\n", (int)ff.size());
	for (auto f : ff) {
		printf("%d %d %d\n", f.u, f.v, f.x);
	}
	return 0;
}
