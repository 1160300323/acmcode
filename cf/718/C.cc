#include <bits/stdc++.h>

using namespace std;

#define ll long long
int n;
int b[515][515];
bool ok(int i, int j) {
	return i && j && i <= n && !b[i][j];
}
void dfs(int i, int j, int x, int r) {
	b[i][j] = x;
	if (1 == r) return;
	if (ok(i, j - 1)) dfs(i, j - 1, x, r - 1);
	else dfs(i + 1, j, x, r - 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &b[i][i]);
	for (int i = 1; i <= n; ++i) {
		dfs(i, i, b[i][i], b[i][i]);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("%d ", b[i][j]);
		}
		puts("");
	}
	return 0;
}
