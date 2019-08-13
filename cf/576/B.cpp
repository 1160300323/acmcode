#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

double H, L;
int main() {
	cin >> H >> L;
	printf("%.12f\n", (L * L - H * H) / (2 * H));
	return 0;
}
