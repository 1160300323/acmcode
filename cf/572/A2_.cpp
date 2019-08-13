#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;

int n, deg[1015], R;
vector<pii> e[1015];
void add(int u, int v, int ww) {
	e[u].pb(pii(v, ww));
	++deg[u];
}
int solve0(int r, int fa, int c) {
	for (auto p : e[r]) {
		if (p.first == fa) continue;
		p.second -= c;
		fa = r;
		return solve0(p.first, r, c);
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
	for (int i = 0, preu = 0, prew; i < (int)e[u].size(); ++i) {
		if (p.first == fa) continue;
		if (preu) {
			int g = solve0(preu, u, prew);
			int h = solve0(p.first, u, prew);
			
	for (int x = head[u], preu = 0, prew; ~x; x = nex[x]) {
		if (to[x] == fa) continue;
		if (preu) {
			int g = solve0(preu, u, prew);
			int h = solve0(to[x], u, prew);
			w[x] -= prew;
			ff.pb(Fuck(g, h, prew));
			ff.pb(Fuck(g, h, w[x] / 2));
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
