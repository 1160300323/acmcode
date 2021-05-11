#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int T, n;
ll c1[1015], c2[1015], ma1[1015], ma2[1015];
int lb(int x) {return x & -x;}
void add(int p, ll x, int *c) {
	for (; p <= 1000; p += lb(p)) c[p] += x;
}
ll query(int p, int *c) {
	int res = 0;
	for (; p; p -= lb(p)) res += c[p];
	return res;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		for (int i = 1; i <= 1000; ++i) {
			c1[i] = c2[i] = 0;
			ma1[i] = ma2[i] = 0;
		}
		scanf("%d", &n);
		ll sum1 = 0, sum2 = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &a, &b);
			if (a < b) {
				sum1 += a;
				add(b - a + 1, a + b, c1);
				ma1[b - a + 1] = max(ma1[b - a + 1], a + b);
				
			} else {
				sum2 += b;
				add(a - b + 1, a + b, c2);
				ma2[a - b + 1] = max(ma2[a - b + 1], a + b);
			}
			ll p = 0, q = 0;
			if (sum1 < sum2) {
				int s = 1, e = 1000, mi, res;
				while (s <= e) {
					mi = s + e >> 1;
					if (sum2 - sum1 <= query(mi, c1)) {
						e = (res = mi) - 1;
					} else {
						s = mi + 1;
					}
				}
				ll del = (sum2 - sum1 - query(res - 1, c1)) % res;
			} else {

		}
	}
	return 0;
}
