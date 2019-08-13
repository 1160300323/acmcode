#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int n;
char s[55][55];
int sum[55][55];
int cal(int x1, int y1, int x2, int y2) {
	return sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x1 - 1][y2] - sum[x2][y1 - 1];
}
int ans[55][55][55][55];
int solve(int x1, int y1, int x2, int y2) {
	if (~ans[x1][y1][x2][y2]) return ans[x1][y1][x2][y2];
	if (x1 == x2 && y1 == y2) return ans[x1][y1][x2][y2] = '#' == s[x1][y1];
	if (x1 > x2 || y1 > y2) return 0;
	int res = max(x2 - x1 + 1, y2 - y1 + 1);
	for (int i = x1; i <= x2 - 1; ++i) {
		for (int j = y1; j <= y2 - 1; ++j) {
			if (cal(i + 1, y1, x2, j) + cal(x1, j + 1, i, y2) == 0) {
				res = min(res, solve(x1, y1, i, j) + solve(i + 1, j + 1, x2, y2));
			}
			if (cal(x1, y1, i, j - 1) + cal(i + 1, j, x2, y2) == 0) {
				res = min(res, solve(x1, j, i, y2) + solve(i + 1, y1, x2, j - 1));
			}
		}
	}
	for (int i = x1 + 1; i <= x2; ++i) {
		for (int j = y1; j <= y2 - 1; ++j) {
			if (cal(x1, y1, i, j - 1) + cal(i + 1, j, x2, y2) == 0) {
                                res = min(res, solve(x1, j, i, y2) + solve(i + 1, y1, x2, j - 1));
                        }
		}
	}
	return res;
}
int main() {
	clr(ans, -1);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= n; ++j) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + '#' == s[i][j];
		}
	}
	printf("%d\n", solve(1, 1, n, n));
	return 0;
}
