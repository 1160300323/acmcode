#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

bool is_p(int x) {
	int m = floor(sqrt(x + 0.5));
	for (int i = 2; i <= m; ++i) {
		if (x % i == 0) return false;
	}
	return true;
}
ll sum[10015];
const int N = 1e9;
int ps[60000015], cnt_p, mi[N + 15];
void pre_p() {
	clr(mi, 0);
	for (int i = 2; i <= N; ++i) {
		if (!mi[i]) {
			ps[++cnt_p] = i;
			mi[i] = i;
		}
		for (int j = 1; j <= cnt_p && ps[j] * i <= N; ++j) {
                        mi[ps[j] * i] = ps[j];
                        if (i % ps[j] == 0) break;
		}
	}
}
int cal(int n) {
	int m = floor(sqrt(n + 0.5));
	int res = 1;
	for (int i = 1; i <= cnt_p && ps[i] <= m; ++i) {
		int cnt = 0;
		while (n % ps[i] == 0) {
			++cnt;
			n /= ps[i];
		}
		if ((ps[i] & 3) == 1) res *= cnt * 3 + 1;
		if (cnt) m = floor(sqrt(n + 0.5));
	}
	if (1 < n && (n & 3) == 1 && is_p(n)) res *= 4;
	return res;
}
int fast_cal(int n) {
	int res = 1;
	while (n != 1) {
		int x = mi[n], cnt = 0;
		do {
			n /= x;
			++cnt;
		} while (mi[n] == x);
		if ((x & 3) == 1) res *= 3 * cnt + 1;
	}
	return res;
}
void pre_table(int siz) {
	int d = 1e9 / siz;
	sum[0] = 0;
	for (int i = 1; i <= siz; ++i) {
		cout << i << endl;
		sum[i] = sum[i - 1];
		for (int j = (i - 1) * d + 1; j <= i * d; ++j) {
			sum[i] += fast_cal(j);
		}
	}
	FILE *fp = fopen("table.out", "w");
	fprintf(fp, "{0, ");
	for (int i = 1; i <= siz; ++i) {
		cout << i << endl;
		fprintf(fp, "%lld, ", sum[i]);
		cout << sum[i] << endl;
		if (i % 10 == 0) fprintf(fp, "\n");
	}
	fprintf(fp, "}");
}
int T, n;
int main() {
	clock_t sta = clock();
	pre_p();
	pre_table(5000);
	clock_t en = clock();
	printf("%.3fs\n", 1.0 * (en - sta) / CLOCKS_PER_SEC);
	scanf("%d", &T);
	return 0;
}
