#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int n, x, y, a[100015];
int main() {
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		int f = 1;
		for (int j = max(1, i - x); j < i; ++j) {
			if (a[i] > a[j]) f = 0;
		}
		for (int j = i + 1; j <= min(i + y, n); ++j) {
			if (a[i] > a[j]) f = 0;
		}
		if (f) return !printf("%d\n", i);
	}
	return 0;
}
