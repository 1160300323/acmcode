#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int T, n, k;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		if (k % 3 == 0) puts(n % 4 ? "Alice" : "Bob");
		else puts(n % 3 ? "Alice" : "Bob");
	}
	return 0;
}
