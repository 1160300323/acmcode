#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a)
#define pii pair<int, int>

const int INF = 0x3f3f3f3f;

int n, p, k;
ll a[300015], ans;
map<ll, ll> mmp;
int main() {
	scanf("%d%d%d", &n, &p, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		ll x = (a[i] * a[i] % p * a[i] % p * a[i] % p - k * a[i] % p + p) % p;
		++mmp[x];
	}

	for (auto p : mmp) {
		ans += p.second * (p.second - 1) >> 1;
	}
	cout << ans;
	return 0;
}
