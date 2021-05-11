#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int T, n;
int sgn(double x) {
	return x < -EPS ? -1 : x < EPS ? 0 : 1;
}
struct Point {
	double x, y;
	Point () {}
	Point (int x, int y) : x(x), y(y) {}
	Point operator - (const Point &p) const {
		return Point(x - p.x, y - p.y);
	}
	Point operator + (const Point &p) const {
		return Point(x + p.x, y + p.y);
	}
	double operator ^ (const Point &p) const {
		return x * p.y - y * p.x;
	}
	Point operator / (const double &k) const {
		return Point(x / k, y / k);
	}
	bool operator < (const Point &p) const {
		return fabs(x - p.x) < EPS ? y < p.y : x < p.x;
	}
	bool operator == (const Point &p) const {
		return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
	}
} p[2015];
Point add[1015];
Point sub[1015];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		if (n <= 4) {
			puts("Y");
			continue;
		}
		int flag = 0;
		if (n & 1) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n / 2; ++j) {
					sub[j] = p[(i + j - 1) % n + 1] - p[(i - j + n - 1) % n + 1];
				}
				int id1 = 0, id2 = 0, f1 = 0, f2 = 0, f = 0;
				for (int j = 2; j <= n / 2; ++j) {
					if (sgn(sub[j] ^ sub[1])) {
						id1 = 1, id2 = j;
					}
				}
				if (id1) {
					for (int j = 1; j <= n / 2; ++j) {
						if (j != id1 && sgn(sub[j] ^ sub[id2])) {
							f1 = id2;
							break;
						}
					}
					for (int j = 1; j <= n / 2; ++j) {
						if (j != id2 && sgn(sub[j] ^ sub[id1])) {
							f2 = id1;
							break;
						}
					}
					if (f1 && f2) continue;
					if (f1) f = f1;
					if (f2) f = f2;
				}
				for (int j = 1; j <= n / 2; ++j) {
					add[j] = (p[(i + j - 1) % n + 1] + p[(i - j + n - 1) % n + 1]) / 2.0;
				}
				id1 = 1 == f ? 2 : 1;
				int ff = 0;
				if (f) {
					for (int j = 1; j <= n / 2; ++j) {
						if (f == j) continue;
						if (sgn((p[i] - add[j]) ^ (p[i] - add[id1]))) {
							ff = 1;
							break;
						}
					}
				} else {
					int cnt1 = 0, cnt2 = 0, cnt3 = 0;
					for (int j = 1; j <= n / 2; ++j) {
						cnt1 += !!sgn((p[i] - add[j]) ^ (p[i] - add[1]));
						if (cnt1 > 1) break;
					}
					for (int j = 1; j <= n / 2; ++j) {
						cnt2 += !!sgn((p[i] - add[j]) ^ (p[i] - add[2]));
						if (cnt2 > 1) break;
					}
					for (int j = 3; j <= n / 2; ++j) {
						cnt3 += !!sgn((add[j] - add[1]) ^ (add[j] - add[2]));
						if (cnt3) break;
					}
					if (cnt1 > 1 && cnt2 > 1 && cnt3) ff = 1;
				}
				if (ff) continue;
				else {
					flag = 1;
					break;
				}
			}
		} else {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n / 2; ++j) {
					sub[j] = p[(i + j - 1) % n + 1] - p[(i - j + n) % n + 1];
				}
				int id1 = 0, id2 = 0, f1 = 0, f2 = 0, f = 0;
				for (int j = 2; j <= n / 2; ++j) {
					if (sgn(sub[1] ^ sub[j])) {
						id1 = 1, id2 = j;
					}
				}
				if (id1) {
					for (int j = 1; j <= n / 2; ++j) {
						if (j != id1 && sgn(sub[j] ^ sub[id2])) {
							f1 = id2;
							break;
						}
					}
					for (int j = 1; j <= n / 2; ++j) {
						if (j != id2 && sgn(sub[j] ^ sub[id1])) {
							f2 = id1;
							break;
						}
					}
					if (f1 && f2) continue;
					if (f1) f = f1;
					if (f2) f = f2;
				}
				for (int j = 1; j <= n / 2; ++j) {
					add[j] = (p[(i + j - 1) % n + 1] + p[(i - j + n) % n + 1]) / 2.0;
				}
				if (1 == f) id1 = 2, id2 = 3;
				else if (2 == f) id1 = 1, id2 = 3;
				else id1 = 1, id2 = 2;
				int ff = 0;
				if (f) {
					for (int j = 1; j <= n / 2; ++j) {
						if (j == f) continue;
						if (sgn((add[id1] - add[j]) ^ (add[id2] - add[j]))) {
							ff = 1;
							break;
						}
					}
				} else {
					int cnt1 = 0, cnt2 = 0, cnt3 = 0;
					for (int j = 1; j <= n / 2; ++j) {
						cnt1 += !!sgn((add[1] - add[j]) ^ (add[2] - add[j]));
						if (cnt1 > 1) break;
					}
					for (int j = 1; j <= n / 2; ++j) {
						cnt2 += !!sgn((add[1] - add[j]) ^ (add[3] - add[j]));
						if (cnt2 > 1) break;
					}
					for (int j = 1; j <= n / 2; ++j) {
						cnt3 += !!sgn((add[2] - add[j]) ^ (add[3] - add[j]));
						if (cnt3 > 1) break;
					}
					if (cnt1 > 1 && cnt2 > 1 && cnt3 > 1) ff = 1;
				}
				if (!ff) {
					flag = 1;
					break;
				}

				for (int j = 1; j < n / 2; ++j) {
					sub[j] = p[(i + j - 1) % n + 1] - p[(i - j + n) % n + 1];
				}
				id1 = 0, id2 = 0, f1 = 0, f2 = 0, f = 0;
				for (int j = 2; j <= n / 2; ++j) {
					if (sgn(sub[1] ^ sub[j])) {
						id1 = 1, id2 = j;
					}
				}
				if (id1) {
					for (int j = 1; j <= n / 2; ++j) {
						if (j != id1 && sgn(sub[j] ^ sub[id2])) {
							f1 = id2;
							break;
						}
					}
					for (int j = 1; j <= n / 2; ++j) {
						if (j != id2 && sgn(sub[j] ^ sub[id1])) {
							f2 = id1;
							break;
						}
					}
					if (f1 && f2) continue;
					if (f1) f = f1;
					if (f2) f = f2;
				}
				for (int j = 1; j < n / 2; ++j) {
					add[j] = (p[(i + j - 1) % n + 1] + p[(i - j + n) % n + 1]) / 2.0;
				}
				id1 = 1 == f ? 2 : 1;
				ff = 0;
				int i2 = (i + n / 2 - 1) % n + 1;
				if (f) {
					for (int j = 1; j < n / 2; ++j) {
						if (f == j) continue;
						if (sgn((p[i2] - p[i]) ^ (p[j] - p[i]))) {
							ff = 1;
							break;
						}
					}
				} else {
					int cnt1 = 0, cnt2 = 0, cnt3 = 0;
					for (int j = 1; j <= n / 2; ++j) {
						cnt1 += !!sgn((p[i] - add[j]) ^ (p[i] - add[i2]));
						if (cnt1 > 1) break;
					}
					for (int j = 1; j <= n / 2; ++j) {
						cnt2 += !!sgn((p[i] - add[j]) ^ (p[i] - add[1]));
						if (cnt2 > 1) break;
					}
					for (int j = 3; j <= n / 2; ++j) {
						cnt3 += !!sgn((p[i2] - add[j]) ^ (p[i2] - add[1]));
						if (cnt3 > 1) break;
					}
					if (cnt1 > 1 && cnt2 > 1 && cnt3 > 1) ff = 1;
				}
				if (ff) continue;
				else {
					flag = 1;
					break;
				}
			}
		}
		puts(flag ? "Y" : "N");
	}
	return 0;
}
