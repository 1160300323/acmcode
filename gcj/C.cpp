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

int T, n, b[105], ans[105], res[105];
map<int, int> mmp;
int main() {
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ++ca) {
		mmp.clear();
		scanf("%d%d", &n, &n);
		for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
		int i = 1;
		for (i = 1; i < n; ++i) {
			if  (b[i] != b[i + 1]) {
				res[i + 1] = __gcd(b[i], b[i + 1]);
				break;
			}
		}
		for (int j = i; j; --j) res[j] = b[j] / res[j + 1];
		for (int j = i + 1; j <= n + 1; ++j) res[j] = b[j - 1] / res[j - 1];
		for (int j = 1; j <= n + 1; ++j) mmp[res[j]];
		int cnt = -1;
		for (map<int, int>::iterator it = mmp.begin(); it != mmp.end(); ++it) {
			it -> second = ++cnt;
		}
		printf("Case #%d: ", ca);
		for (int i = 1; i <= n + 1; ++i) putchar('A' + mmp[res[i]]);
		puts("");
	}
	return 0;
}

