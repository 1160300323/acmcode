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
#define mp make_pair
#define clr(a, x) memset(a, x, sizeof(a))

const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
tree<pli, null_type, greater<pli>, rb_tree_tag, tree_order_statistics_node_update> T;
*/


int T, n;
char s[100015];
struct gg {
	int a, b;
	gg () {}
	gg (int a, int b) : a(a), b(b) {}
	bool operator < (const gg &g) const {
		int f = a < b ? 1 : (a == b ? 0 : -1);
		int f2 = g.a < g.b ? 1 : (g.a == g.b ? 0 : -1);
		if (f != f2) return f > f2;
		if (f >= 0) return a < g.a;
		else return b > g.b;
	}
} g[100015];

int main() {
	scanf("%d", &T);
	while (T--) {
		ll ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf(" %s", s + 1);
			int l = strlen(s + 1), a = 0, b = 0;
			for (int j = 1; j <= l; ++j) {
				if ('(' == s[j]) {
					++b;
				} else {
					if (b) {
						--b, ++ans;
					} else {
						++a;
					}
				}
			}
			g[i] = gg(a, b);
		}
		sort(g + 1, g + n + 1);
		for (int i = 1, cnt = 0; i <= n; ++i) {
			int pp = min(cnt, g[i].a);
			ans += pp;
			cnt -= pp;
			cnt += g[i].b;
		}
		printf("%lld\n", ans * 2);
	}
	return 0;
}
