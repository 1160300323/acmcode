#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

char s[100015];
int sum[26][100015], l[26], r[26], k;
vector<int> ps[26];
char ans[100015];
int main() {
	while (~scanf("%s%d", s + 1, &k)) {
		int ls = strlen(s + 1);
		for (int i = 0; i < 26; ++i) {
			ps[i].clear();
			scanf("%d%d", &l[i], &r[i]);
		}
		for (int i = 1; i <= ls; ++i) {
			for (int j = 0; j < 26; ++j) {
				sum[j][i] = sum[j][i - 1];
			}
			sum[s[i] - 'a'][i]++;
			ps[s[i] - 'a'].pb(i);
		}
		int id_ans = 0;
		for (int i = 0; i <= ls; ) {
			int j, tp;
			for (j = 0; j < 26; ++j) {
				if (!r[j]) continue;
				tp = upper_bound(ps[j].begin(), ps[j].end(), i) - ps[j].begin();
				if (tp == ps[j].size()) continue;
				tp = ps[j][tp];
				--l[j], --r[j], --k;
				int suml = 0, sumr = 0, f = 1;
				for (int o = 0; o < 26; ++o) {
					int tmp = sum[o][ls] - sum[o][tp];
					if (tmp < l[o]) {
						f = 0;
						break;
					}
					suml += max(0, l[o]);
					sumr += max(0, r[o]);
				}
				if (k < suml || sumr < k) f = 0;
				++l[j], ++r[j], ++k;
				if (f) break;
			}
			if (26 == j) {
				id_ans = -1;
				break;
			}

			l[j] = max(l[j] - 1, 0);
			r[j] = max(r[j] - 1, 0);
			--k;
			ans[++id_ans] = s[tp];
			i = tp;
			if (!k) break;
		}
		if (~id_ans) {
			ans[++id_ans] = 0;
			puts(ans + 1);
		} else {
			puts("-1");
		}
	}
	return 0;
}
