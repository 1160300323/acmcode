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

struct point {
	double x, y;
	int index;
	point () {}
	point (double x, double y, int index) : x(x), y(y), index(index) {}
	bool operator < (const point &p) const {
		return atan2(y, x) < atan2(p.y, p.x);
	}
	void input(int i) {
		scanf("%lf%lf", &x, &y);
		index = i;
	}
} p[3015];
int T, n;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= 3 * n; ++i) {
			p[i].input(i);
		}
		sort(p + 1, p + 3 * n + 1);
		for (int i = 1; i <= n; ++i) {
			printf("%d %d %d\n", p[3 * i - 2].index, p[3 * i - 1].index, p[3 * i].index);
		}
	}
	return 0;
}
