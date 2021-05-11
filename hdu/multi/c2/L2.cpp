#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int n, c, k, a[100015], bad[100015], ans;
int sum[100015], vis[100015], arr[100015], idd;
void solve(int l, int r) {
	if (r - l + 1 < ans || r - l + 1 < k) return;
	if (r < l) return;
	idd = 0;
	for (int i = l; i <= r; ++i) {
		++sum[a[i]];
		if (!vis[a[i]]) arr[++idd] = a[i];
		vis[a[i]] = 1;
	}
	int f = 1;
	for (int i = 1; i <= idd; ++i) {
		if (sum[arr[i]] < k) {
			bad[arr[i]] = 1;
			f = 0;
		}
	}
	for (int i = l; i <= r; ++i) sum[a[i]] = vis[a[i]] = 0;
	if (f) ans = r - l + 1;
	else {
		int pre = l - 1;
		for (int i = l; i <= r; ++i) {
			if (bad[a[i]]) {
				solve(pre + 1, i - 1);
				pre = i;
			}
		}
		solve(pre + 1, r);
	}
	for (int i = l; i <= r; ++i) {
		bad[a[i]] = 0;
	}
}
int main() {
	while (~scanf("%d%d%d", &n, &c, &k)) {
		ans = 0;
		for (int i = 1; i <= c; ++i) {
			bad[i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		solve(1, n);
		printf("%d\n", ans);
	}
	return 0;
}
