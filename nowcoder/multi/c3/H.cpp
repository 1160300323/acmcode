#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int T, n, px, py;
struct Point {
	int x, y; 
	Point () {}
	Point (int x, int y) : x(x), y(y) {}
	bool operator < (const Point &p) const {
		return (x - px) * (p.y - py) - (p.x - px) * (y - py) < 0;
	}
} p[1015];
int main() {
	srand((int)time(NULL));
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		int flag = 0;
		while (!flag) {
			py = -1001 - rand() % 1000, px = rand() % 1000;
			sort(p + 1, p + n + 1);
			if ((p[n / 2].x - px) * (p[n / 2 + 1].y - py) == (p[n / 2 + 1].x - px) * (p[n / 2].y - py)) continue;
			flag = 1;
			printf("%d %d %d %d\n", px, py, p[n / 2].x + p[n / 2 + 1].x - px, p[n / 2].y + p[n / 2 + 1].y - py);
		}
	}
	return 0;
}
