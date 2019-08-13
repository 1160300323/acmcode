#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

#define Double double

int T, n;
int xx, yy;
int sgn(ll x) {
	return x < 0 ? -1 : x ? 1 : 0;
}
struct Point {
	ll x, y;
	Point () {}
	Point (ll x, ll y) : x(x), y(y) {}
	Point operator - (const Point &p) const {
		return Point(x - p.x, y - p.y);
	}
	ll operator ^ (const Point &p) const {
		return x * p.y - y * p.x;
	}
	ll operator | (const Point &p) const {
		return x * p.x + y * p.y;
	}
	bool operator < (const Point &p) const {
		ll res = (x - xx) * (p.y - yy) - (p.x - xx) * (y - yy);
		if (res) return res > 0;
		return abs(x - xx) + abs(y - yy) < abs(p.x - xx) + abs(p.y - yy);
	}
} p[105], q[105];
struct Seg {
	Point s, e;
	Seg () {}
	Seg (Point s, Point e) : s(s), e(e) {}
	bool in(Point p) {
		return sgn((p - s) ^ (p - e)) == 0 && ((p - s) | (p - e)) <= 0;
	}
	bool insect(Seg s2) {
		int f1 = sgn((s2.s - s) ^ (s2.e - s));
		int f2 = sgn((s2.s - e) ^ (s2.e - e));
		int f3 = sgn((s - s2.s) ^ (e - s2.s));
		int f4 = sgn((s - s2.e) ^ (e - s2.e));
		if (in(s2.s) || in(s2.e) || s2.in(s) || s2.in(e)) return true;
		return f1 * f2 < 0 && f3 * f4 < 0;
	}
} s[105];
struct Pol {
	int n;
	Point p[105];
	void ini(Point pp[105], int N) {
		yy = INF;
		for (int i = 1; i <= N; ++i) {
			if (pp[i].y < yy) {
				xx = pp[i].x;
				yy = pp[i].y;
			}
		}
		sort(pp + 1, pp + N + 1);
		n = 0;
		if (1 <= N) p[++n] = pp[1];
		if (2 <= N) p[++n] = pp[2];
		for (int i = 3; i <= N; ++i) {
			while (n >= 2 && ((pp[i] - p[n - 1]) ^ (p[n] - p[n - 1])) >= 0) --n;
			p[++n] = pp[i];
		}
	}
	bool in(Point pp) {
		for (int i = 1; i <= n; ++i) {
			if (Seg(p[i], p[i % n + 1]).in(pp)) return true;
		}
		int f = sgn((pp - p[1]) ^ (pp - p[2]));
		for (int i = 2; i <= n; ++i) {
			int tf = sgn((pp - p[i]) ^ (pp - p[i % n + 1]));
			if (tf != f) return false;
		}
		return true;
	}
	void out() {
		for (int i = 1; i <= n; ++i) {
			cout << p[i].x << ' ' << p[i].y << endl;
		}
		cout << endl;
	}
} pol[2];

int main() {
	//freopen("02", "r", stdin);
	//freopen("M.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int pid = 0, qid = 0;
		for (int i = 1; i <= n; ++i) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			if (1 == z) p[++pid] = Point(x, y);
			else q[++qid] = Point(x, y);
		}
		pol[0].ini(p, pid);
		pol[1].ini(q, qid);
		for (int i = 1; i <= pid; ++i) {
			if (!pol[0].in(p[i])) puts("GG");
		}
		//cout << pid << ' ' << pol[0].n << endl;
		//pol[0].out();
		int f = 1;
		for (int i = 1; i <= pol[0].n; ++i) {
			Seg s1 = Seg(pol[0].p[i], pol[0].p[i % pol[0].n + 1]);
			for (int j = 1; j <= pol[1].n; ++j) {
				Seg s2 = Seg(pol[1].p[j], pol[1].p[j % pol[1].n + 1]);
				if (s1.insect(s2)) {
					f = 0;
					break;
				}
			}
		}
		for (int v = 0; v <= 1; ++v) {
			for (int i = 1; i <= pol[v].n; ++i) {
				if (pol[!v].in(pol[v].p[i])) f = 0;
			}
		}
		puts(f ? "Successful!" : "Infinite loop!");
	}
	return 0;
}
