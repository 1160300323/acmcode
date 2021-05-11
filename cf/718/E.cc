#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 998244353;

int T;
int n, a[200015];
ll ans, sum;
//P+CC+
void count1() {
	int sum_tmp = 0;
	for (int i = 1; i <= n - 2; ++i) {
		sum_tmp += a[i];
		if (sum < sum_tmp * 2) {
			ans += n - 2 - i + 1;
			return;
		}
	}
}
// (PC)*P*
void sub_count2(int sta, int en, ll sum_tmp) {
	ll sum_arr = 0;
	for (int i = sta; i <= en; ++i) sum_arr += a[i];
	for (int i = sta + 1; i <= en; i += 2) {
		sum_arr -= a[i];
		if (sum < (sum_tmp + sum_arr) * 2) ans = (ans + 1) % MOD;
	}
}
// C*(PC)*P*
void sub_count1(int sta, int en, ll sum_tmp) {
	ll sum_arr = 0;
	for (int i = sta; i <= en; ++i) sum_arr += a[i];
	for (int i = sta - 1, j = sta; i <= en; i += 2) {
		while (j <= en - 1 && sum < 2 * (sum_tmp + sum_arr)) {
			j += 2;
			sum_arr -= a[j - 1];
		}
		while (i <= j - 3 && 2 * (sum_tmp + sum_arr) <= sum) {
			j -= 2;
			sum_arr += a[j + 1];
		}
		ans += (en + 1 - j) / 2 + 1;
		ans %= MOD;
		sum_arr -= a[i + 1] + a[i + 2];
	}
	sum_arr = 0;
	for (int i = sta + 1; i <= en; ++i) sum_arr += a[i];
	for (int i = sta, j = sta + 1; i <= en; i += 2) {
		while (j <= en - 1 && sum < 2 * (sum_tmp + sum_arr)) {
			j += 2;
			sum_arr -= a[j - 1];
		}
		while (i <= j - 3 && 2 * (sum_tmp + sum_arr) <= sum) {
			j -= 2;
			sum_arr += a[j + 1];
		}
		ans += (en + 1 - j) / 2 + 1;
		ans %= MOD;
		sum_arr -= a[i + 1] + a[i + 2];
	}
}
//(PC)(0/1) C+ (PC)* P+ (PC)(0/1)
void count2() {
	if (2 <= n) {
		// C C*(PC)*P* P
		sub_count1(2, n - 1, a[n]);
	}
	if (4 <= n) {
		// PCC C*(PC)*P* P
		sub_count1(4, n - 1, a[1] + a[n]);
		// C C*(PC)*P* PPC
		sub_count1(2, n - 3, a[n - 2] + a[n - 1]);
	}
	if (6 <= n) {
		// PCC C*(PC)*P* PPC
		sub_count1(4, n - 3, a[1] + a[n - 2] + a[n - 1]);
	}
}
//(PC)*P+(PC)(0/1)
void count3() {
	if (1 <= n) {
		// (PC)*P* P
		sub_count2(1, n - 1, a[n]);
	}
	if (3 <= n) {
		// (PC)*P* PPC
		sub_count2(1, n - 3, a[n - 2] + a[n - 1]);
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ans = sum = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		count1();
		count2();
		count3();
		printf("%lld\n", ans);
	}
	return 0;
}
