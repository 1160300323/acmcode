#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int T;
ll n;
vector<int> c1, c2;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		c1.clear(); c2.clear();
		for (int i = 0; i <= 60; ++i) {
			if (n & 1ll << i) {
				if (i & 1) c2.pb(i);
				else c1.pb(i);
			}
		}
		int sum = 2 * c2.size() + c1.size();
		if (sum % 3 == 0) {
			printf("%d %lld\n", 1, n);
		} else {
			vector<int> d1, d2;
			if (sum % 3 == 1) {
				int i = 0, j = 0, f1 = 0, f2 = 0;
				for (; i < (int)c1.size(); ) {
					d1.pb(c1[i]);
					f1 = 1;
					++i;
					break;
				}
				for (; i < (int)c1.size(); ) {
					d2.pb(c1[i]);
					f2 = 1;
					++i;
					break;
				}
				if (!f1) {
					d1.pb(c2[0]), d1.pb(c2[1]);
					d2.pb(c2[2]), d2.pb(c2[3]);
				} else if (!f2) {
					d2.pb(c2[0]), d2.pb(c2[1]);
				}
			} else {
				int i = 0, j = 0, f1 = 0, f2 = 0;
				for (; j < (int)c2.size(); ) {
					d1.pb(c2[j]);
					f1 = 1;
					++j;
					break;
				}
				for (; j < (int)c2.size(); ) {
					d2.pb(c2[j]);
					f2 = 1;
					++j;
					break;
				}
				if (!f1) {
					d1.pb(c1[0]), d1.pb(c1[1]);
					d2.pb(c1[2]), d2.pb(c1[3]);
				} else if (!f2) {
					d2.pb(c1[0]), d2.pb(c1[1]);
				}
			}
			printf("2");
			ll x1 = 0, x2 = 0;
			for (auto b : c1) {
				x1 |= 1ll << b;
				x2 |= 1ll << b;
			}
			for (auto b : c2) {
				x1 |= 1ll << b;
				x2 |= 1ll << b;
			}
			for (auto c : d1) {
				x1 ^= 1ll << c;
			}
			for (auto c : d2) {
				x2 ^= 1ll << c;
			}
			printf(" %lld %lld\n", x1, x2);
		}
	}
	return 0;
}
