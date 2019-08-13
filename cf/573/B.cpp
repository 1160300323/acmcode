#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>

const int INF = 0x3f3f3f3f;
int n, a[100015];
ll sum;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i] - i + 1;
	}
	sort(a + 1, a + n + 1);
	int f = a[1] == a[2];
	if (!a[1] && !a[2]) f = 2;
	for (int i = 2; i <= n - 1; ++i) {
		if (a[i] == a[i + 1]) {
			++f;
			f += a[i - 1] + 1 == a[i] || a[i - 1] == a[i];
		}
	}
	if (1 < f) return !printf("cslnb");
	puts(sum & 1 ? "sjfnb" : "cslnb");
	return 0;
}
