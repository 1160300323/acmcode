#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>

const int INF = 0x3f3f3f3f;

int n;
ll a[100015];
int main() {
	scanf("%d", &n);
	ll tot = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		tot |= a[i];
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += __builtin_popcountll(tot ^ a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
