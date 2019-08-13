#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int q, n, m, cnt1[50015], cnt2[50015];
char s[50015];
vector<char> b[50015];
int main() {
	scanf("%d", &q);
	for (int i = 1; i <= 50000; ++i) b[i].pb('.');
	while (q--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) cnt1[i] = 0;
		for (int j = 1; j <= m; ++j) cnt2[j] = 0;
		for (int i = 1; i <= n; ++i) b[i].resize(1);
		for (int i = 1; i <= n; ++i) {
			scanf("%s", s + 1);
			for (int j = 1; j <= m; ++j) {
				b[i].pb(s[j]);
				cnt1[i] += '*' == s[j];
				cnt2[j] += '*' == s[j];
			}
		}
		int ans = n + m;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				ans = min(ans, n + m - cnt1[i] - cnt2[j] - ('.' == b[i][j]));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
