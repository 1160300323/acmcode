#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MOD = 998244353;

int w, h;
ll mpow(ll x, ll y) {
	ll res = 1;
	for (; y; y >>= 1) {
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD;
	}
	return res;
}
int main() {
	scanf("%d%d", &w, &h);
	printf("%lld\n", mpow(2, w + h));
	return 0;
}
