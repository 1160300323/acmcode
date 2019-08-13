#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int n, m;
vector<pii> ans;
bool is_p(int x) {
	for (int i = 2; i < x; ++i) {
		if (x % i == 0) return false;
	}
	return true;
}
void solve(int n, int r) {
	for (int i = 1; i <= n; ++i) {
		ans.pb(pii(i, i % n + 1));
	}
	int d = n / 2;
	for (int i = 1; i <= r; ++i) {
		ans.pb(pii(i, i + d));
	}
}
int main() {
	scanf("%d", &n);
	if (7 == n) {
		solve(6, 0);
		for (int i = 1; i <= 5; ++i) ans.pb(pii(7, i));
	} else {
		for (int m = n; ; ++m) {
			if (is_p(m)) {
				solve(n, m - n);
				break;
			}
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto p : ans) {
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}
