#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int T, n, m, deg[300015], tdeg[300015];
pii edges[500015];
struct gg {
	int v, id;
	gg () {}
	gg (int v, int id) : v(v), id(id) {}
	bool operator < (const gg &g) const {
		return deg[v] == deg[g.v] ? id < g.id : deg[v] < deg[g.v];
	}
};
set<gg> ss[300015];
int f[300015];
bool match() {
	vector<int> ans;
	priority_queue<pii, vector<pii>, greater<pii> > que;
	for (int i = 1; i <= 3 * n; ++i) {
		f[i] = 0;
		que.push(pii(deg[i], i));
	}
	while (que.size()) {
		pii pp = que.top(); que.pop();
		int u = pp.second;
		if (f[u]) continue;
		f[u] = 1;
		for (auto p : ss[u]) {
			int v = p.v, id = p.id;
			if (!f[v]) {
				ans.pb(id);
				f[v] = 1;
				break;
			}
		}
	}
	if (ans.size() >= n) {
		puts("Matching");
		for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
		puts("");
		return true;
	}
	return false;
}
bool indSet() {
	priority_queue<pii, vector<pii>, greater<pii> > que;
	for (int i = 1; i <= 3 * n; ++i) {
		f[i] = 0;
		que.push(pii(deg[i], i));
	}
	vector<int> ans;
	while (que.size()) {
		pii pp = que.top(); que.pop();
		int u = pp.second;
		if (f[u]) continue;
		for (auto p : ss[u]) {
			int v = p.v;
			f[v] = 1;
		}
		ans.pb(u);
	}
	if (ans.size() >= n) {
		puts("IndSet");
		for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
                puts("");
                return true;
	}
        return false;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= 3 * n; ++i) {
			deg[i] = 0;
			ss[i].clear();
		}
		for (int i = 1; i <= m; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			++deg[u], ++deg[v];
			edges[i] = pii(u, v);
		}
		for (int i = 1; i <= m; ++i) {
			int u = edges[i].first, v = edges[i].second;
			ss[u].insert(gg(v, i)), ss[v].insert(gg(u, i));
		}
		if (!match() && !indSet()) puts("Impossible");
	}
	return 0;
}
