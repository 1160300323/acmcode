#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cctype>
#include <cassert>
#include <bitset>
#include <ctime>

using namespace std;

#define pau system("pause")
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pli pair<ll, int>
#define pil pair<int, ll>
#define clr(a, x) memset(a, x, sizeof(a))

const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define TREE tree<pli, null_type, greater<pli>, rb_tree_tag, tree_order_statistics_node_update>
TREE T;
*/

int T, n, B;
int sum[1035], res[5][1035];
char s[1035];
void send(int b) {
	int l = 1 << b;
	for (int i = 1; i <= n / l; ++i) {
		for (int j = (i - 1) * l + 1; j <= i * l; ++j) {
			putchar(i & 1 ? '1' : '0');
		}
	}
	for (int j = n / l * l + 1; j <= n; ++j) {
		putchar(n / l + 1 & 1 ? '1' : '0');
	}
	puts(""); fflush(stdout);
}
void get(int b) {
	int l = 1 << b; scanf("%s", s + 1);
	for (int i = 1, p = 1; i <= (n - 1) / l + 1; i += 2) {
		int q = p + res[b + 1][(i - 1) * l + 1] - 1;
		int k = p;
		while (k <= q && '1' == s[k]) ++k;
		res[b][(i - 1) * l + 1] = k - p;
		p = k;
		while (k <= q && '0' == s[k]) ++k;
		res[b][i * l + 1] = k - p;
		p = q + 1;
	}
}
void solve2(int b) {
	send(b);
	get(b);
	if (0 == b) return;
	solve2(b - 1);
}
void solve(int b) {
	send(b);	
	scanf("%s", s + 1);
	int l = 1 << b;
	for (int i = 1, j = 1; i <= (n - 1) / l + 1; ++i) {
		int k = j;
		while (k <= n - B && s[k] == s[j]) ++k;
		res[b][(i - 1) * l + 1] = k - j;
		j = k;
	}
	solve2(b - 1);
}
int main() {
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ++ca) {
		int f;
		scanf("%d%d%d", &n, &B, &f);
		clr(res, 0);
		solve(4);
		for (int i = 1; i <= n; ++i) {
			if (!res[0][i]) printf("%d ", i - 1);
		}
		puts(""); fflush(stdout);
	}
	return 0;
}

