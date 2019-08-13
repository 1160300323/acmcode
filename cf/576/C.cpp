#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int n, I, a[400015], sum[400015];
map<int, int> mmp;
int main() {
	scanf("%d%d", &n, &I);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		mmp[a[i]];
	}
	int cnt_id = 0;
	for (map<int, int>::iterator it = mmp.begin(); it != mmp.end(); ++it) {
		it -> second = ++cnt_id;
	}
	for (int i = 1; i <= n; ++i) {
		++sum[mmp[a[i]]];
	}
	for (int i = 1; i <= cnt_id; ++i) {
		sum[i] += sum[i - 1];
	}
	int kk = I * 8 / n;
	int K = n;
	if (kk <= 20) K = 1 << kk;
	int ans = 0;
	for (int i = 1; i <= cnt_id; ++i) {
		int j = min(i + K - 1, cnt_id);
		ans = max(ans, sum[j] - sum[i - 1]);
	}
	printf("%d\n", n - ans);
	return 0;
}
