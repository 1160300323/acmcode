#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

char s[1000015];
int cnt1[1000015], cnt2[1000015];
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'v' && s[i - 1] != 'v') {
			cnt2[i] = cnt2[i - 1] + 1;
		} else {
			cnt2[i] = cnt2[i - 1];
		}
		cnt1[i] = cnt1[i - 1] + ('v' == s[i]);
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		if ('o' == s[i]) {
			ans += (ll)(cnt1[i] - cnt2[i]) * (cnt1[n] - cnt1[i] - cnt2[n] + cnt2[i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
