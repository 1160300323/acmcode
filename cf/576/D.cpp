#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int n, q, a[200015], lazy[800015];
void pushdown(int i) {
	lazy[i << 1] = max(lazy[i << 1], lazy[i]);
	lazy[i << 1 | 1] = max(lazy[i << 1 | 1], lazy[i]);
	lazy[i] = 0;
}
void update1(int i, int l, int r, int x, int y, int z) {
	if (x <= l && r <= y) {
		lazy[i] = max(lazy[i], z);
		return;
	}
	int mi = l + r >> 1;
	pushdown(i);
	if (x <= mi) update1(i << 1, l, mi, x, y, z);
	if (mi < y) update1(i << 1 | 1, mi + 1, r, x, y, z);
}
void update2(int i, int l, int r, int x, int z) {
	if (l == r) {
		lazy[i] = 0;
		a[x] = z;
		return;
	}
	int mi = l + r >> 1;
	pushdown(i);
	if (x <= mi) update2(i << 1, l, mi, x, z);
	if (mi < x) update2(i << 1 | 1, mi + 1, r, x, z);
}
int query(int i, int l, int r, int x) {
	if (l == r) return max(a[x], lazy[i]);
	pushdown(i);
	int mi = l + r >> 1;
	if (x <= mi) return query(i << 1, l, mi, x);
	else return query(i << 1 | 1, mi + 1, r, x);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	scanf("%d", &q);
	while (q--) {
		int op, p, x;
		scanf("%d", &op);
		if (1 == op) {
			scanf("%d%d", &p, &x);
			update2(1, 1, n, p, x);
		} else {
			scanf("%d", &x);
			update1(1, 1, n, 1, n, x);
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", query(1, 1, n, i));
	}
	return 0;
}
