#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int max_n = 33;

const string INF = "999999999999999999999999999999999999999999999";
int T;
string Y;
bool cmp_less(string A, string B) {
	if (A.length() < B.length()) return true;
	if (A.length() > B.length()) return false;
	for (int i = 0; i < A.length(); ++i) {
		if (A[i] < B[i]) return true;
		if (A[i] > B[i]) return false;
	}
	return false;
}
string construct(string sta_str) {
	ll sta_ll = stoll(sta_str);
	string res = sta_str;
	do {
		sta_ll += 1;
		res += to_string(sta_ll);
	} while (!cmp_less(Y, res));
	return res;
}

string solve(int sta_l) {
	if (Y.length() < sta_l) return INF;

	string sta_str = "1";
	for (int i = 0; i < sta_l; ++i) sta_str += "0";
	string res = construct(sta_str);

	string prefix_str = Y.substr(0, sta_l);
	ll prefix_ll = stoll(prefix_str);
	for (int d = -10; d <= 10; ++d) {
		ll sta_ll = prefix_ll + d;
		if (sta_ll <= 0) continue;
		string tmp = construct(to_string(sta_ll));
		if (cmp_less(tmp, res)) res = tmp;
	}

	return res;
}

int main() {
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		cin >> Y;
		string X = INF;
		for (int l = 1; l <= 10; ++l) {
			string res = solve(l);
			if (cmp_less(res, X)) X = res;
		}
		printf("Case #%d: %s\n", _, X.c_str());
	}
	return 0;
}
/*
7
2020
2021
68000
101
9999
1000000000000
999999999999999999
*/
