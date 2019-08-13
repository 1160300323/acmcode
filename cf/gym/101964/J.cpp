#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back

const int INF = 0x3f3f3f3f;

int n, m;
struct Edge {
	int v; ll w;
	Edge () {}
	Edge (int v, ll w) : v(v), w(w) {}
};
struct EE {
	int u, v;
	ll wr, wt;
	EE () {}
	EE (int u, int v, ll wr, ll wt) : u(u), v(v), wr(wr), wt(wt) {}
} ee[200015];
vector<Edge> er[100015], _er[100015];
ll disr[100015], disrr[100015];
void Dij() {
	clr(disr, INF);
	disr[n] = 0;
	priority_queue<pli, vector<pli>, greater<pli> > que;
	que.push(pli(0, n));
	while (que.size()) {
		pli pp = que.top(); que.pop();
		ll d = pp.first; int u = pp.second;
		if (disr[u] < d) continue;
		for (auto e : er[u]) {
			int v = e.v; ll w = e.w;
			if (d + w < disr[v]) {
				disr[v] = d + w;
				que.push(pli(disr[v], v));
			}
		}
	}
}
int pt, pr, pathr[100015];
pii patht[100015];
ll suf[100015], pre[100015];
vector<int> ans;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v, wr, wt;
		scanf("%d%d%d%d", &u, &v, &wt, &wr);
		er[v].pb(Edge(u, wr));
		_er[u].pb(Edge(v, wr));
		ee[i] = EE(u, v, wr, wt);
	}
	Dij();
	scanf("%d", &pt);
	for (int i = 1; i <= pt; ++i) {
		scanf("%d%d", &patht[i].first, &patht[i].second);
	}
	scanf("%d", &pr);
	for (int i = 1; i <= pr; ++i) {
		scanf("%d", &pathr[i]);
	}
	for (int i = pr; i; --i) {
		disrr[i] = disrr[i + 1] + ee[pathr[i]].wr;
	}
	for (int i = 1; i <= pt; ++i) {
		pre[i] = pre[i - 1] + ee[patht[i].first].wt + patht[i].second;
	}
	pre[pt] -= patht[pt].second;
	for (int i = pt; i; --i) {
		suf[i] = suf[i + 1] + ee[patht[i].first].wt;
	}
	ll cnt = 0;
	for (int i = 1; i <= pr; ++i) {
		int u = ee[pathr[i]].u;
		int id = lower_bound(pre + 1, pre + pt + 1, cnt) - pre;
		if (id == pt + 1) continue;
		ll delta = 0;
		if (id < pt && cnt < pre[id] - patht[id].second) delta = patht[id].second;
		ll timet = pre[id] + suf[id + 1] - delta;
		for (auto p : _er[u]) {
			int v = p.v; ll w = p.w;
			if (v == ee[pathr[i]].v) continue;
			ll timer = cnt + w + disr[v];
			if (timer < cnt + disrr[i] && timer <= timet && timer == cnt + disr[u]) {
				ans.pb(u);
				break;
			}
		}
		cnt += ee[pathr[i]].wr;
	}
	printf("%d\n", (int)ans.size());
	sort(ans.begin(), ans.end());
	for (auto u : ans) printf("%d ", u);
	return 0;
}
/*
   8 12
   1 2 2 10
   2 3 1 10
   3 8 2 10
   1 4 10 3
   4 5 10 2
   5 6 10 4
   6 8 10 2
   1 7 10 5
   4 7 10 2
   5 7 10 2
   6 7 10 1
   7 8 10 1
   3
   1 3
   2 2
   3 0
   4
   4 5 6 7

   6 6 
   1 4 1 3
   4 6 1 1
   4 2 1 6
   2 6 6 6
   3 4 2 3
   1 3 4 5
   2
   1 2
   2 0
   4
   6 5 3 4
*/
