#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long

const int mod = 998244353;
const int maxn = 5005;

long long fac[maxn], ifac[maxn];
 
long long ksm(long long a, long long b) {
	long long ret = 1;
	for (; b; b>>=1, a = a*a % mod)
		if (b & 1) ret = ret * a % mod;
	return ret;
}
 
void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++) 
		fac[i] = fac[i-1] * i % mod;
	ifac[n] = ksm(fac[n], mod-2);
	for (int i = n; i; i--)
		ifac[i-1] = ifac[i]*i % mod;
}
 
long long C(long long a, long long b) {
	if (a < 0 or b < 0 or a < b) return 0;
	return fac[a] * ifac[b] % mod * ifac[a-b] % mod;
}

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	rep(i, 0, n) cin >> v[i];
	sort(all(v));
	vector<vector<int> > dp(n+2, vector<int>(n+2));

	vector<int> cnt;
	for(int i = 0; i < n; ) {
		int j = 0;
		while(i+j < n && v[i+j] == v[i]) j++;
		cnt.push_back(j);
		i += j;
	}

	dp[sz(cnt)][0] = 1;
	for(int i = sz(cnt), sum = 0; i > 0; i--) {
		for(int j = 0; j <= n / 2; j++) {
			int can = max(j-1, 0ll) + (j == n/2) - (sum - j);
			cout << "i, j, can=" << i << ','<< j << ',' << can << endl;
			dp[i-1][j+1] = (dp[i-1][j+1] + dp[i][j]*C(can, cnt[i-1]-1)) % mod;
			dp[i-1][j] = (dp[i-1][j] + dp[i][j]*C(can, cnt[i-1])) % mod;
		}
		sum += cnt[i-1];
	}
	cout << dp[0][n/2] << endl;

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n/2; j++) {
			cout << "dp[" << i << "][" << j << "]=" << dp[i][j] << endl;
		}
	}
	
}

signed main() {
	init(maxn);
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		// cout << "Case " << i << ": ";
		solve();
	}
}
