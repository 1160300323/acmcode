#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

const int MOD = 1e9 + 9;
const int B = 131;
char s[200015];
ll Hash[200015], p[200015];
ll dp[200015], pp, qq;
ll getHash(int sta, int en) {
	return ((Hash[en] - Hash[sta - 1] * p[en - sta + 1]) % MOD + MOD) % MOD;
}
int main() {
	p[0] = 1;
	for (int i = 1; i <= 200000; ++i) {
		p[i] = p[i - 1] * B % MOD;
	}
	while (~scanf("%s", s + 1)) {
		scanf("%lld%lld", &pp, &qq);
		int l = strlen(s + 1);
		for (int i = 1; i <= l; ++i) {
			Hash[i] = Hash[i - 1] * B + s[i];
		}
		for (int i = 1; i <= l; ++i) {
			dp[i] = dp[i - 1] + pp;
			if (~i & 1) {
				int mi = i >> 1;
				if (getHash(1, mi) == getHash(mi + 1, i)) {
					dp[i] = min(dp[i], dp[i >> 1] + qq);
				}
			}
		}
		printf("%lld\n", dp[l]);
	}
	return 0;
}
