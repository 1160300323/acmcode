#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

ll p, q;
ll mul(ll x, ll y, ll m) {
	ll res = 0;
	for (; y; y >>= 1) {
		if (y & 1) res = (res + x) % m;
		x = (x + x) % m;
	}
	return res;
}
long long power(long long v, long long p, long long m)
{
	long long r = 1;
	while(p)
	{
		if(p & 1) r = mul(r, v, m);
		v = mul(v, v, m);
		p >>= 1;
	}
 
	return r;
}
 
bool witness(long long a, long long p)
{
	int k = 0;
	long long q = p - 1;
	while((q & 1) == 0)
		++k, q >>= 1;
	long long v = power(a, q, p);
	if(v == 1 || v == p - 1)
		return false;   // probably prime number
	while(k-- != 0)
	{
		v = mul(v, v, p);
		if(v == p - 1)
			return false;
	}
 
	return true; // composite number
}
 
bool miller_rabin(long long p)
{
	if(p == 2) return true;
	if(p % 2 == 0) return false;
 
	for(int i = 0; i != 50; ++i)
	{
		long long a = std::rand() % (p - 1) + 1;
		if(witness(a, p))
			return false;
	}
 
	return true;
}
int T;
int main() {
	scanf("%d", &T);
	while (T--) {

	cin >> p;
	if (2 == p) {
		cout << 1 << endl;
		continue;
	}
	for (ll i = p - 1; i; --i) {
		if (miller_rabin(i)) {
			q = i;
			break;
		}
	}
	ll res = 1;
	for (ll i = q + 1; i < p - 1; ++i) {
		res = mul(res, power(i, p - 2, p),  p);
	}
	printf("%lld\n", res);
	}
	return 0;
}
