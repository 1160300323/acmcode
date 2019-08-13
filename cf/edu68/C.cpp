#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int q, cnt1[26], cntp[26];
char s[105], t[105], p[105];
int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%s %s %s", s + 1, t + 1, p + 1);
		int ls = strlen(s + 1), lt = strlen(t + 1), lp = strlen(p + 1);
		clr(cntp, 0), clr(cnt1, 0);
		for (int i = 1; i <= lp; ++i) ++cntp[p[i] - 'a'];
		int i, j, f = 1;
		for (i = 1, j = 1; i <= ls && j <= lt; ) {
			while (j <= lt && s[i] != t[j]) {
				++cnt1[t[j] - 'a'];
				++j;
			}
			if (j > lt) {
				f = 0;
				break;
			}
			++i, ++j;
		}
		for (; j <= lt; ++j) ++cnt1[t[j] - 'a'];
		for (int i = 0; i < 26; ++i) {
			if (cnt1[i] > cntp[i]) {
				f = 0;
				break;
			}
		}
		puts(f ? "YES" : "NO");
	}
	return 0;
}
/*
0 3 6 9
1 2 4 5 7 8 
0 3
1 2 4 5
*/
