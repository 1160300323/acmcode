#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int INF = 1e9 + 7;

int n, m, k;
int b[515][515][2];
int e_r[515][515], e_c[515][515];
const int dir[][4] = { {0, 1, 0, 0},
											 {0, -1, 0, -1},
											 {1, 0, 0, 0},
											 {-1, 0, -1, 0}
										 };
bool ok(int i, int j) { return i && i <= n && j && j <= m; }
void update(int i, int j, int r) {
	int f = r & 1;
	int pre_f = !f;
	b[i][j][f] = INF;
	for (int d = 0; d < 4; ++d) {
		int pre_i = i + dir[d][0], pre_j = j + dir[d][1];
		if (!ok(pre_i, pre_j)) continue;
		int step_i = dir[d][2], step_j = dir[d][3], step_row_f = (dir[d][0] != 0);
		b[i][j][f] = min(b[i][j][f], b[pre_i][pre_j][pre_f] + \ 
										 (step_row_f ? e_r[i + step_i][j + step_j] : e_c[i + step_i][j + step_j]));
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			scanf("%d", &e_c[i][j]);
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &e_r[i][j]);
		}
	}
	if (k & 1) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				printf("-1 ");
			}
			puts("");
		}
		return 0;
	}
	k >>= 1;
	for (int rep = 1; rep <= k; ++rep) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				update(i, j, rep);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%d ", 2 * b[i][j][k & 1]);
		}
		puts("");
	}
	return 0;
}
