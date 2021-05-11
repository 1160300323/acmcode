#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int T, n, k;
set<int> ss;
vector<int> vec;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		ll m = n / k;
		if (m % 2 == 0) {
			puts("yes");
			ll mm = m / 2;
			for (int i = 1; i <= k; ++i) {
				vec.clear();
				for (int j = 1; j <= mm; ++j) {
					vec.pb((i - 1) * mm + j);
					vec.pb(n - (i - 1) * mm - j + 1);
				}
				sort(vec.begin(), vec.end());
				for (int i = 0; i < (int)vec.size() - 1; ++i) {
					printf("%d ", vec[i]);
				}
				printf("%d\n", vec[(int)vec.size() - 1]);
			}
		} else {
			if (n % 2 == 0) {
				puts("no");
				continue;
			}
			if (1 == m) {
				if (1 == n) {
					puts("yes");
					puts("1");
				} else {
					puts("no");
				}
				continue;
			}
			ss.clear();
			for (int i = 1; i <= n; ++i) ss.insert(i);
			ll d = m * (n + 1) / 2;
			puts("yes");
			for (int i = 1; i <= k; ++i) {
				vec.clear();
				ll tsum = 0;
				while (tsum < d) {
					int x = *--ss.upper_bound(d - tsum);
					ss.erase(x);
					tsum += x;
					vec.pb(x);
				}
				for (int i = 0; i < (int)vec.size() - 1; ++i) printf("%d ", vec[i]);
				printf("%d\n", vec[(int)vec.size() - 1]);
			}
		}
	}
	return 0;
}
