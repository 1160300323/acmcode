#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int T, n, k;
struct gg {
	vector<int> vec;
	bool operator < (const gg &g) const {
		int n = vec.size();
		for (int i = 1; i < n; ++i) {
			if (vec[i] - vec[i - 1] < g.vec[i] - g.vec[i - 1]) return true;
			if (vec[i] - vec[i - 1] > g.vec[i] - g.vec[i - 1]) return false;
		}
	}
} g[50015];
int p[11];
int main() {
	p[0] = 1; 
	for (int i = 1; i <= 10; ++i) p[i] = p[i - 1] * i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		int a[9];
		if (n <= 8) {
			for (int i = 1; i <= n; ++i) a[i] = i;
			for (int i = 1; i <= p[n]; ++i) {
				vector<int> vec;
				for (int j = 1; j <= n; ++j) {
					vec.pb(a[j]);
				}
				g[i].vec = vec;
				next_permutation(a + 1, a + n + 1);
			}
			sort(g + 1, g + p[n] + 1);
			for (int i = 0; i < n - 1; ++i) printf("%d ", g[k].vec[i]);
			printf("%d\n", g[k].vec[n - 1]);
		} else {
			printf("%d ", n);
			for (int i = 2; i <= n - 8; ++i) printf("%d ", i - 1);
			for (int i = 1; i <= 8; ++i) a[i] = n - (9 - i);
			a[0] = 0;
			for (int i = 1; i <= p[8]; ++i) {
				vector<int> vec;
				for (int j = 0; j <= 8; ++j) {
					vec.pb(a[j]);
				}
				g[i].vec = vec;
				next_permutation(a + 1, a + 9);
			}
			sort(g + 1, g + p[8] + 1);
			for (int i = 1; i <= 7; ++i) printf("%d ", g[k].vec[i]);
			printf("%d\n", g[k].vec[8]);
		}
	}
	return 0;
}
