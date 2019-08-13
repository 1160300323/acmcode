#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;

char s[55];
ll dp[2][3];
int main() {
	scanf("%s", s + 1);
	int l = strlen(s + 1);
	dp[0][0] = 1;
	for (int i = 1; i <= l; ++i) {
		int f = i & 1;
		for (int j = 0; j < 3; ++j) {
			int k = (j + s[i] - '0') % 3;
			dp[f][k] = (dp[!f][k] + dp[!f][j]) % MOD;
		}
	}
	printf("%lld\n", (dp[l & 1][0] - 1 + MOD) % MOD);
	return 0;
}
