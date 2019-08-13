import java.util.*;
import java.math.BigInteger;

public class C {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n, T; BigInteger B;
		BigInteger b[] = new BigInteger[105];
		BigInteger res[] = new BigInteger[105];
		TreeMap<BigInteger, Integer> mmp = new TreeMap<BigInteger, Integer>();
		T = cin.nextInt();
		for (int ca = 1; ca <= T; ++ca) {
			mmp.clear();
			B = cin.nextBigInteger(); n = cin.nextInt();
			for (int i = 1; i <= n; ++i) {
				b[i] = cin.nextBigInteger();
			}
			int i = 1;
			for (i = 1; i < n; ++i) {
				if (b[i].compareTo(b[i + 1]) != 0) {
					res[i + 1] = b[i].gcd(b[i + 1]);
					break;
				}
			}
			for (int j = i; j > 0; --j) {
				res[j] = b[j].divide(res[j + 1]);
			}
			for (int j = i + 2; j <= n + 1; ++j) {
				res[j] = b[j - 1].divide(res[j - 1]);
			}
			for (i = 1; i <= n + 1; ++i) {
				mmp.put(res[i], 0);
			}
			int c = 0;
			for (BigInteger t : mmp.keySet()) {
				mmp.put(t, c);
				c = c + 1;
			}
			System.out.printf("Case #%d: ", ca);
			for (i = 1; i <= n + 1; ++i) {
				System.out.print((char)(mmp.get(res[i]) + 'A'));
			}
			System.out.println();
		}
	}
}
