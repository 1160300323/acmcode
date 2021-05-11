#include <bits/stdc++.h>

using namespace std;

int T, n;
char s[3][200015];
int cnt[3][2];
string out(int id1, int id2, int f) {
  string ans = "";
  for (int i = 1, j = 1; i <= 2 * n || j <= 2 * n; ) {
    while (i <= 2 * n && s[id1][i] != '0' + f) ans += s[id1][i], ++i;
    while (j <= 2 * n && s[id2][j] != '0' + f) ans += s[id2][j], ++j;
    if (i <= 2 * n || j <= 2 * n) ans += '0' + f;
    ++i, ++j;
  }
  return ans;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < 3; ++i) {
      scanf("%s", s[i] + 1);
      cnt[i][0] = cnt[i][1] = 0;
      for (int j = 1; j <= 2 * n; ++j) {
        cnt[i][0] += '0' == s[i][j];
	cnt[i][1] += '1' == s[i][j];
      }
    }
    string ans;
    for (int i = 0; i < 3; ++i) {
      for (int j = i + 1; j < 3; ++j) {
        for (int f = 0; f <= 1; ++f) {
	  if (cnt[i][f] >= n && cnt[j][f] >= n) {
	    ans = out(i, j, f);
	    break;
	  }
	} 
	if (ans.length() > 0) break;
      }
      if (ans.length() > 0) break;
    }
    for (auto c : ans) putchar(c); puts("");
  }
  return 0;
}  
