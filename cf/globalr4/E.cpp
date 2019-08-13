#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

char s[1000015];
vector<int> id;
int main() {
	scanf("%s", s + 1);
	int l = strlen(s + 1), f = 0;
	for (char c1 = 'a'; c1 <= 'c'; ++c1) {
		for (char c2 = 'a'; c2 <= 'c'; ++c2) {
			if (c1 == c2) continue;
			id.clear();
			for (int i = 1, j = l; i <= j; ++i, --j) {
				while (i <= j && s[i] != c1 && s[i] != c2) ++i;
				while (i <= j && s[j] != c1 && s[j] != c2) --j;
				if (i > j) break;
				if (s[i] == c1 || s[j] == c1) {
					while (i <= j && s[i] != c1) ++i;
					while (i <= j && s[j] != c1) --j;
				}
				id.pb(i);
				if (i < j) id.pb(j);
			}
			if (id.size() >= l / 2) {
				f = 1;
				break;
			}
		}
		if (f) break;
	}
	sort(id.begin(), id.end());
	for (auto p : id) {
		putchar(s[p]);
	}
	return 0;
}
