#include <bits/stdc++.h>

using namespace std;

#define ll long long

int T;
int n;
ll k;

int a[100015];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%lld\n", &n, &k); k--; 
    vector<int> bits;
    while (k) { bits.push_back(k & 1); k >>= 1; }
    if (n < bits.size() + 1) { puts("-1"); continue; }
    for (int i = 1; i <= n; ++i) a[i] = i;
    for (int i = 0; i < bits.size(); ++i) {
      int j = i;
      while (j < bits.size() && bits[j] == 1) ++j;
      reverse(a + n - j, a + n - i + 1);
      i = j;
    }
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");
  }
  return 0;
}
/*
6
1 1
1 2
3 3
6 5
3 4
*/
