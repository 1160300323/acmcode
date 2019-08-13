#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define clr(a, x) memset(a, x, sizeof(a))

const int MaxN = 400;
const int MaxM = 15000;
const int INF = 0x3f3f3f3f;

int n, m;
int head[MaxN + 15], to[MaxM * 2 + 15], nex[MaxM * 2 + 15];
int tot, f[MaxM * 2 + 15], cost[MaxM * 2 + 15];
void add(int u, int v, int f0, int c) {
	nex[++tot] = head[u]; head[u] = tot;
	f[tot] = f0; cost[tot] = c;
}
int dis[MaxN + 15], pre[MaxN + 15], inque[MaxN + 15];
bool spfa(int s, int t) {
	clr(dis, INF); clr(inque, 0);
	dis[s] = 0; inque[s] = 1;
	queue<int> que; que.push(s);
	while (que.size()) {
		int u = que.front(); que.pop();
		inque[u] = 0;
		for (int x = head[u]; ~x; x = nex[x]) {
			int v = to[x];
			if (dis[u] + cost[x] < dis[v]) {
				dis[v] = dis[u] + cost[x];
				pre[v] = u;
				if (!inque[v]) {
					inque[v] = 1;
					que.push(v);
				}
			}
		}
	}
	return dis[t] != INF;
}

pii MFMC(int s, int t) {
	while (spfa(s, t)) {
		
	}
}
int main() {
	clr(head, -1); tot = -1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v, f0, c;
		scanf("%d%d%d%d", &u, &v, &f0, &c);
		add(u, v, f0, c);
		add(u, v, 0, -c);
	}
	pii ans = MFMC(1, n);
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}
