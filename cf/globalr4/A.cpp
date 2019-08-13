#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int n, a[105];
vector<int> ans;
int main() {
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	ll cnt = a[1];
	ans.pb(1);
	for (int i = 2; i <= n; ++i) {
		if (a[i] * 2 <= a[1]) {
			cnt += a[i];
			ans.pb(i);
		}
	}
	if (cnt * 2 > sum) {
		printf("%d\n", (int)ans.size());
		for (auto i : ans) printf("%d ", i);
	} else {
		puts("0");
	}
	return 0;
}
