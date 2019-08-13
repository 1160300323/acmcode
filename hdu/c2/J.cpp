#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MOD = 1e6+3;
ll n;
ll p[1000015];
int main() {
	p[0] = 1;
	for (int i = 1; i <= MOD; ++i) p[i] = p[i - 1] * i % MOD;
	while (~scanf("%lld", &n)) {
		if (n >= MOD) puts("0");
		else printf("%lld\n", p[n]);
	}
	return 0;
}
