#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a)
#define pii pair<int, int>

const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n, k, a[1015];
ll dp[1015][1015], sum[1015][1015], ans;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int j = 1; j <= n; ++j) sum[0][j] = j;
	for (int x = 1; x <= 100000 / (k - 1); ++x) {
		for (int i = 1; i <= k - 1; ++i) {
			for (int j1 = 1, j2 = 2; j2 <= n; ++j2) {
				while (a[j2] - a[j1] >= x) ++j1;
				dp[i][j2] = sum[i - 1][j1 - 1];
				sum[i][j2] = (sum[i][j2 - 1] + dp[i][j2]) % MOD;
			}
		}
		ans += sum[k - 1][n];
	}
	printf("%lld\n", ans % MOD);
	return 0;
}
