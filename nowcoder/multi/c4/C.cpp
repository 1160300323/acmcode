#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int n;
int a[3000015], b[3000015];
int L[3000015], R[3000015];
pii sta[3000015];
int id_sta;
int get_int() {
	int res = 0, f = 1;
	char c = getchar();
	while (c != '-' && !isdigit(c)) {
		c = getchar();
	}
	if ('-' == c) {
		f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * f;
}
void pre_a() {
	sta[++id_sta] = pii(-INF, 0);
	for (int i = 1; i <= n; ++i) {
		while (sta[id_sta].first >= a[i]) {
			int tid = sta[id_sta].second;
			L[tid] = sta[id_sta - 1].second + 1;
			R[tid] = i - 1;
			--id_sta;
		}
		sta[++id_sta] = pii(a[i], i);
	}
	while (id_sta > 1) {
		int tid = sta[id_sta].second;
		L[tid] = sta[id_sta - 1].second + 1;
		R[tid] = n;
		--id_sta;
	}
}
ll ma[12000015], mi[12000015], sum[3000015];
void pushup(int i) {
	ma[i] = max(ma[i << 1], ma[i << 1 | 1]);
	mi[i] = min(mi[i << 1], mi[i << 1 | 1]);
}
void build(int i, int l, int r) {
	if (l == r) {
		ma[i] = mi[i] = sum[l];
		return;
	}
	int mi = l + r >> 1;
	build(i << 1, l, mi);
	build(i << 1 | 1, mi + 1, r);
	pushup(i);
}
ll query_mi(int i, int l, int r, int x, int y) {
	if (x <= l && r <= y) {
		return mi[i];
	}
	int mi = l + r >> 1;
	ll res1 = 1e18, res2 = 1e18;
	if (x <= mi) res1 = query_mi(i << 1, l, mi, x, y);
	if (mi < y) res2 = query_mi(i << 1 | 1, mi + 1, r, x, y);
	return min(res1, res2);
}
ll query_ma(int i, int l, int r, int x, int y) {
	if (x <= l && r <= y) {
		return ma[i];
	}
	int mi = l + r >> 1;
	ll res1 = -1e18, res2 = -1e18;
	if (x <= mi) res1 = query_ma(i << 1, l, mi, x, y);
	if (mi < y) res2 = query_ma(i << 1 | 1, mi + 1, r, x, y);
	return max(res1, res2);
}
int main() {
	n = get_int();
	for (int i = 1; i <= n; ++i) {
		a[i] = get_int();
	}
	for (int i = 1; i <= n; ++i) {
		b[i] = get_int();
		sum[i] = sum[i - 1] + b[i];
	}
	pre_a();
	build(1, 0, n);
	ll ans = -6e18;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > 0) {
			ll mi1 = query_mi(1, 0, n, L[i] - 1, i - 1);
			ll ma2 = query_ma(1, 0, n, i, R[i]);
			ans = max(ans, (ma2 - mi1) * a[i]);
		} else {
			ll ma1 = query_ma(1, 0, n, L[i] - 1, i - 1);
			ll mi2 = query_mi(1, 0, n, i, R[i]);
			ans = max(ans, (mi2 - ma1) * a[i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
