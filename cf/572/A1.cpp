#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a)
#define pii pair<int, int>

const int INF = 0x3f3f3f3f;

int n, deg[100015];
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		++deg[u], ++deg[v];
	}
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 2) return !printf("NO");
	}
	printf("YES");
	return 0;
}
