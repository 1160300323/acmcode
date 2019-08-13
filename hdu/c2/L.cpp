#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int n, c, k, a[100015], ids[100015];
int p[100015];
vector<int> pos[100015];
int ma[400015];
void pushup(int i) {
	ma[i] = max(ma[i << 1], ma[i << 1 | 1]);
}
void build(int i, int l, int r) {
	if (l == r) {
		ma[i] = 0;
		return;
	}
	int mi = l + r >> 1;
	build(i << 1, l, mi);
	build(i << 1 | 1, mi + 1, r);
	pushup(i);
}
void update(int i, int l, int r, int x, int y) {
	if (l == r) {
		ma[i] = y;
		return;
	}
	int mi = l + r >> 1;
	if (x <= mi) update(i << 1, l, mi, x, y);
	else update(i << 1 | 1, mi + 1, r, x, y);
	pushup(i);
}
int query(int i, int l, int r, int x, int y) {
	if (y < x) return 0;
	if (x <= l && r <= y) {
		return ma[i];
	}
	int mi = l + r >> 1;
	int res1 = 0, res2 = 0;
	if (x <= mi) res1 = query(i << 1, l, mi, x, y);
	if (mi < y) res2 = query(i << 1 | 1, mi + 1, r, x, y);
	return max(res1, res2);
}
bool check1(int l, int r) {
	map<int, int> mmp;
	for (int i = l; i <= r; ++i) ++mmp[a[i]];
	for (auto p : mmp) {
		if (p.second < k) return false;
	}
	return true;
}
bool inque[100015];
int main() {
	while (~scanf("%d%d%d", &n, &c, &k)) {
		for (int i = 1; i <= c; ++i) {
			pos[i].clear();
			inque[i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			pos[a[i]].pb(i);
			ids[i] = (int)pos[a[i]].size() - 1;
		}
		for (int i = 1; i <= n; ++i) {
			if (ids[i] + k <= pos[a[i]].size()) {
				p[i] = pos[a[i]][ids[i] + k - 1];
			} else {
				p[i] = n + 1;
			}
		}
		p[n + 1] = n + 1;
		for (int i = 1; i <= n; ++i) cout << p[i] << ' ';
		build(1, 1, n);
		int ans = 0;
		for (int i = 1, j = 1; i <= n && j <= n; ++i) {
			for (int tt = i; tt <= j; ++tt) {
				if (inque[a[tt]]) continue;
				j = max(j, p[tt]);
				update(1, 1, n, tt, p[tt]);
				inque[a[tt]] = 1;
			}
			if (j <= n) ans = max(ans, j - i + 1);
			int tr = n + 1;
			if (ids[i] + 1 < pos[a[i]].size()) {
				tr = pos[a[i]][ids[i] + 1];
			}
			int ts = query(1, 1, n, i + 1, tr - 1);
			if (ts < tr) {
				ans = tr - i - 1;
			}
			if (ans < tr - i - 1) {
				if (check1(i + 1, tr - 1)) {
					ans = tr - i - 1;
				}
			}
			update(1, 1, n, i, 0);
			if (tr < n + 1) update(1, 1, n, tr, p[tr]);
			if (1 == k) inque[a[i]] = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}
