#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;


int main() {
	ll x1, x2, x3, y1, y2, y3;
	while (~scanf("%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3)) {
		ll S = abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
		printf("%lld\n", S * 11);
	}
	return 0;
}
