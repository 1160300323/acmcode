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

char s[155]; int T, l;
char a[155], b[155];
int main() {
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ++ca) {
		scanf("%s", s + 1);
		printf("Case #%d: ", ca);
		l = strlen(s + 1);
		for (int i = 1; i <= l; ++i) {
			a[i] = s[i];
			b[i] = '0';
		}
		--a[1], ++b[1];
		for (int i = 1; i <= l; ++i) {
			if ('4' == a[i]) {
				--a[i], ++b[i];
			}
		}
		int i1 = 1, i2 = 1;
		while (i1 <= l && a[i1] == '0') ++i1;
		if (i1 == l + 1) {
			putchar('1'); putchar(' ');
			for (int i = 1; i < l; ++i) putchar('9');
		} else {
			for (int i = i1; i <= l; ++i) putchar(a[i]); putchar(' ');
			for (int i = 1, f = 0; i <= l; ++i) {
				if (b[i] != '0') f = 1;
				if (f) putchar(b[i]);
			}
		}
		puts("");
	}
	return 0;
}

