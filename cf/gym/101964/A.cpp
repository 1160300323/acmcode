#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>

const int INF = 0x3f3f3f3f;

ll n, ans;
int m, c[21], a[21], b[21], d[21];
ll check(int m1, int m2) {
	if (m1 != m2) {
		//cout << m1 << ' ' << m2 << endl;
		for (int i = m2; i > m1; --i) {
			b[i] = c[i] + d[i + 1] * 10 - d[i];
		}
		for (int i = 0, j = m1; i <= j; ++i, --j) {
			b[i] = b[m2 - i];
			a[i] = c[i] + 10 * d[i + 1] - b[i] - d[i];
			a[j] = a[i];
			b[j] = c[j] + 10 * d[j + 1] - a[j] - d[j];
		}
		if (a[0] == 0 || b[0] == 0) return 0;
		for (int i = 0; i <= m; ++i) {
			if (a[i] < 0 || a[i] > 9 || b[i] < 0 || b[i] > 9) return 0;
			if (a[i] + b[i] + d[i] != c[i] + d[i + 1] * 10) return 0;
			if (i <= m2 && b[i] != b[m2 - i]) return 0;
		}
		/*for (int i = 0; i <= m + 1; ++i) {
			cout << a[i] << ' ' << b[i] << ' ' << c[i] << ' ' << d[i] << endl;
		}*/
		return 1;
	} else {
		for (int i = 0; i <= m1; ++i) {
			a[i] = c[i] + d[i + 1] * 10 - d[i];
		}
		if (a[0] == 0) return 0;
		for (int i = 0; i <= m; ++i) {
			if (a[i] < 0 || a[i] > 18) return 0;
			if (a[i] + d[i] - d[i + 1] * 10 != c[i]) return 0;
			if (i <= m1 && a[i] != a[m1 - i]) return 0;
		}
		ll res = max(0, min(min(a[0] - 1, 19 - a[0]), 9));
		for (int i = 1, j = m1 - 1; i <= j; ++i, --j) {
			res *= min(min(a[i] + 1, 19 - a[i]), 10);
		}
		return res;
	}
}

int main() {
	cin >> n;
	m = log10(n + 0.5);
	for (int i = 0; i <= m; ++i) {
		c[i] = n % 10;
		n /= 10;
	}
	/*int f = 2;
	for (int i = 0; i <= m; ++i) if (c[i] != c[m - i]) f = 0;
	ans += f;*/
	for (int mask = 0; mask < 1 << m; ++mask) {
		for (int i = 0; i < m; ++i) d[i + 1] = mask >> i & 1;
		clr(a, 0);
		for (int m1 = m; ~m1; --m1) {
			a[m1 + 1] = 0;
			for (int m2 = m; m2 >= max(m - 1, m1); --m2) {
				b[m2 + 1] = 0;
				ans += (2 - (m1 == m2)) * check(m1, m2);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
