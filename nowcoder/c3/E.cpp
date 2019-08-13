#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

struct pii {
	int x, l, r;
	pii () {}
	pii (int x, int l, int r) : x(x), l(l), r(r) {}
} quemi[515], quema[515];
int T, n, m, a[515][515];
int mi[515], ma[515];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				mi[j] = INF;
				ma[j] = 0;
			}
			for (int j = i; j <= n; ++j) {
				for (int jj = 1; jj <= n; ++jj) {
					mi[jj] = min(mi[jj], a[j][jj]);
					ma[jj] = max(ma[jj], a[j][jj]);
				}
				int mi1 = 1, mi2 = 0, ma1 = 1, ma2 = 0;
				for (int k = 1, l = 1; l <= n; ++l) {
					int boundmi = l, boundma = l;
					while (mi1 <= mi2 && quemi[mi2].x >= mi[l]) {
						boundmi = quemi[mi2].l;
						--mi2;
					}
					while (ma1 <= ma2 && quema[ma2].x <= ma[l]) {
						boundma = quema[ma2].l;
						--ma2;
					}
					quemi[++mi2] = pii(mi[l], boundmi, l);
					quema[++ma2] = pii(ma[l], boundma, l);
					while (mi1 <= mi2 && ma1 <= ma2 && quema[ma1].x - quemi[mi1].x > m) {
						int rmi = quemi[mi1].r, rma = quema[ma1].r;
						if (rmi < rma) {
							++mi1;
						} else if (rma < rmi) {
							++ma1;
						} else {
							++mi1, ++ma1;
						}
					}
					k = mi1 <= mi2 ? max(k, max(quemi[mi1].l, quema[ma1].l)) : l + 1;
					ans = max(ans, (l - k + 1) * (j - i + 1));
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
