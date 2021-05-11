#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int T, n, k, ans[22];
ll p[22];
int main() {
	p[0] = 1;
	for (int i = 1; i <= 20; ++i) p[i] = p[i - 1] * i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		--k;
		int d = 0, e = INF;
		int m1 = k / p[n - 2], m2 = k % p[n - 2];
		for (d = n - 1; d; --d) {
			if (m1 < n - d) {
				e = m1;
				break;
			}
			m1 -= n - d;
		}
		if (INF == e) {
			for (d = -1; d >= 1 - n; --d) {
				if (m1 < n + d) {
					e = m1;
					break;
				}
				m1 -= n + d;
			}
		}
		int k1, k2;
		for (int i = n; i; --i) {
			if (0 < i - d && i - d <= n) {
				if (!e--) {
					k1 = i;
					k2 = i - d;
					break;
				}
			}
		}
		ans[1] = k1, ans[2] = k2;
		for (int i = 1, j = 3; i <= n; ) {
			while (i == k1 || i == k2) ++i;
			ans[j++] = i++;
		}
		while (m2--) {
			next_permutation(ans + 3, ans + n + 1);
		}
		for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}
