#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>

const int INF = 0x3f3f3f3f;

ll n, k, p[100015];
int m;
int main() {
	scanf("%lld%d%lld", &n, &m, &k);
	for (int i = 1; i <= m; ++i) scanf("%lld", &p[i]);
	int ans = 0;
	for (int i = 1; i <= m; ) {
		ll c = (p[i] - i) / k;
		int s = i, e = m, mi, res;
		while (s <= e) {
			mi = s + e >> 1;
			if (p[mi] - i < (c + 1) * k) s = (res = mi) + 1;
			else e = mi - 1;
		}
		++ans;
		i = res + 1;
	}
	printf("%d\n", ans);
	return 0;
}
