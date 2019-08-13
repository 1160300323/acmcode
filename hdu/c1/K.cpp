#include <bits/stdc++.h>

using namespace std;

#define N 10000005

int phi[N], prime[N];
long long sum[N];

void getphi()
{
	  int tot = 0;
	    memset(phi, 0, sizeof(phi));
	      phi[1] = 1;
	        for (int i = 2; i <= 10000000; i++)
			  {
				      if (!prime[i])
					          {
							        phi[i] = i - 1;
								      prime[++tot] = i;
								          }
				          for (int j = 1; j <= tot && prime[j] * i < 10000000; j++)
						      {
							            prime[prime[j] * i] = 1;
								          if (i % prime[j] == 0)
										        {
												        phi[prime[j] * i] = phi[i] * prime[j];
													        break;
														      }
									        phi[prime[j] * i] = phi[i] * (prime[j] - 1);
										    }
					    }
}

void read(__int128 &a)
{
	  __int128 x = 0;
	    char c = getchar();
	      while (c > '9' || c < '0')
		          c = getchar();
	        while (c >= '0' && c <= '9')
			  {
				      x = x * 10LL + c - '0';
				          c = getchar();
					    }
		  a = x;
}

struct Point
{
	  __int128 num;
	    __int128 x;
	      __int128 ans;
	        int id;
} a[20];

void output(__int128 i)
{
	  __int128 x = i;
	    int st[105];
	      int tot = 0;
	        while (x > 0)
			  {
				      st[++tot] = x % 10;
				          x /= 10;
					    }
		  for (int i = tot; i >= 1; i--)
			    {
				        printf("%d", st[i]);
					  }
		    puts("");
}

bool cmp(Point a, Point b)
{
	  return a.x < b.x;
}

bool cmpp(Point a, Point b)
{
	  return a.id < b.id;
}

int main()
{
	  getphi();
	    for (int i = 1; i <= 10000000; i++)
		      {
			          for (int j = i; j <= 10000000; j += i)
					      {
						            sum[j] += 1LL * i * phi[j / i];
							        }
				    }
	      int T;
	        scanf("%d", &T);
		  for (int i = 1; i <= T; i++)
			    {
				        read(a[i].num);
					    a[i].id = i;
					        for (__int128 j = 1; j <= 10000000; j++)
							    {
								          if (j * j * j <= a[i].num && (j + 1) * (j + 1) * (j + 1) > a[i].num)
										        {
												        a[i].x = j;
													        a[i].ans = 0;
														        break;
															      }
									      }
						  }
		    sort(a + 1, a + T + 1, cmp);
		      __int128 tmp = 0;
		        int id = 1;
			  if (a[id].x == 1)
				      id++;
			    for (int i = 1; i <= 10000000; i++)
				      {
					          __int128 xx = i;
						      tmp = tmp + ((xx + 1) * (xx + 1) * (xx + 1) - xx * xx * xx) / xx * sum[i];
						          if (i != 1)
								        tmp += xx;
							      while (i == a[id].x - 1 && id <= T)
								          {
										        a[id].ans += tmp, id++;
											    }
							        }
			      for (int i = 1; i <= T; i++)
				        {
						    __int128 m = a[i].num - a[i].x * a[i].x * a[i].x + 1;
						        a[i].ans += (m / a[i].x) * sum[a[i].x];
							    for (__int128 j = 1; j <= m % a[i].x; j++)
								        {
										      a[i].ans += __gcd(j - 1, a[i].x);
										          }
							      }
			        sort(a + 1, a + T + 1, cmpp);
				  for (int i = 1; i <= T; i++)
					    {
						        output(a[i].ans);
							  }
				    return 0;
}
