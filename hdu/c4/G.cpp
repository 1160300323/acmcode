#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int T, a[16];
int main() {
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i < 16; ++i) scanf("%d", &a[i]);
		int inv = 0;
		for (int i = 0; i < 16; ++i) {
			if (!a[i]) continue;
			for (int j = i + 1; j < 16; ++j) {
				if (!a[j]) continue;
				inv += a[i] > a[j];
			}
		}
		puts(inv & 1 ? "No" : "Yes");
	}
	return 0;
}
