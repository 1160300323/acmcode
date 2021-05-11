#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int max_n = 33;

int T;
int n, k;
int p[max_n];
int cal(int d) {
	return d / 2;
}
int solve2() {
	p[0] = 0, p[n + 1] = k + 1;
	int res = 0;
	for (int i = 1; i <= n + 1; ++i) {
		res = max(res, p[i] - p[i - 1] - 1);
	}
	return res;
}
int main() {
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
		sort(p + 1, p + n + 1);
		int res2 = solve2();
		p[n + 1] = k  - p[n];
		for (int i = n; i >= 2; --i) p[i] = cal(p[i] - p[i - 1]);
		p[1] = p[1] - 1;
		sort(p + 1, p + n + 2);
		int total = max(p[n + 1] + p[n], res2);
		printf("Case #%d: %.9f\n", _, 1.0 * total / k);
	}
	return 0;
}
/*
3
3 10
1 8 9
*/
