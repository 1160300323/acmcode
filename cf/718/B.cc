#include <bits/stdc++.h>

using namespace std;

#define ll long long
int T;
int n, m;
int b[105][105];
map<int, int> mmp[105], total_mmp;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		total_mmp.clear();
		for (int i = 1; i <= n; ++i) {
			mmp[i].clear();
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &b[i][j]);
				mmp[i][b[i][j]]++;
				total_mmp[b[i][j]]++;
			}
		}
		for (int i = 1; i <= m; ++i) {
			int mi = total_mmp.begin()->first;
			for (int j = 1, f = 0; j <= n; ++j) {
				if (!f && mmp[j].begin()->first == mi) {
					if (!--mmp[j][mi]) mmp[j].erase(mi);
					if (!--total_mmp[mi]) total_mmp.erase(mi);
					b[j][i] = mi;
					f = 1;
				} else {
					int x = (--mmp[j].end())->first;
					if (!--mmp[j][x]) mmp[j].erase(x);
					if (!--total_mmp[x]) total_mmp.erase(x);
					b[j][i] = x;
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				printf("%d ", b[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
