#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;

int m, n, p[105];
vector<int> e[105];
int vis[105], path[105];
int dfs(int u, int d) {
	if (vis[u] || -1 == d) return 0;
	int res = p[u]; vis[u] = 1;
	for (auto v : e[u]) {
		if (path[v]) continue;
		res += dfs(v, d - 1);
	}
	return res;
}
int check(int u, int v) {
	int dis[105], pre[105];
	clr(dis, -1), clr(pre, 0);
	queue<int> que; que.push(u); dis[u] = 0;
	while (que.size()) {
		int x = que.front(); que.pop();
		for (auto y : e[x]) {
			if (~dis[y]) continue;
			que.push(y);
			dis[y] = dis[x] + 1;
			pre[y] = x;
		}
	}
	int dd = dis[v], cnt = 1;
	clr(vis, 0); clr(path, 0);
	for (int x = v; x != u; x = pre[x]) path[x] = 1; path[u] = 1;
	for (int x = v; x != u; x = pre[x]) {
		cnt += dfs(x, min(dis[x], dd - dis[x]));
	}
	//printf("u = %d, v = %d, dd = %d, cnt = %d\n", u, v, dd, cnt);
	if (cnt >= m) return dd;
	else return -1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
	for (int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		e[u].pb(v), e[v].pb(u);
	}
	if (1 == m) return !printf("0");
	int ans = INF;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (!p[i] || !p[j]) continue;
			int res = check(i, j);
			if (~res) {
				ans = min(ans, res);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
/*
   9 4
   1 0 1 0 1 0 0 1 1
   1 2
   2 4
   2 3
   4 5
   1 6
   6 7
   6 8
   7 9
   */
