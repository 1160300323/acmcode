#include <bits/stdc++.h>

using namespace std;

#define ll long long
int T;
ll n;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		if (n % 2050) {
			puts("-1");
		} else {
			n /= 2050;
			int ans = 0;
			while (n) {
				ans += n % 10;
				n /= 10;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
