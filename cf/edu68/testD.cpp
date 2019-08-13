#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int k = 6;
int sg[1005];
int main() {
	sg[0] = 0; sg[1] = sg[2] = 1;
	for (int i = 3; i <= 100; ++i) {
		if (i >= k) if (!sg[i - k]) sg[i] = 1;
		if (!sg[i - 1] || !sg[i - 2]) sg[i] = 1;
		printf("sg[%d] = %d\n", i, sg[i]);
	}
	return 0;
}
