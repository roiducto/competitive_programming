#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long

int n, x, y;
string a, b;
void solve2() {
	vector<int> v(n);
	rep(i, 0, n) v[i] = (a[i] != b[i]);
	int diff = 0;
	for(int i = 0; i < n; i++) {
		if(v[i]) diff++;
	}
	int neb = 0;
	for(int i = 0; i < n-1; i++) {
		if(v[i] && v[i+1]) neb = 1;
	}
	if(diff % 2 == 1) cout << "-1\n";
	else if(diff == 2 && neb == 1) cout << min(x, y*2) << endl;
	else cout << y * (diff / 2) << endl;


}

void solve() {
	cin >> n >> x >> y;
	cin >> a >> b;
	if(y <= x) {
		solve2();
		return;
	}

	vector<int> diff;
	rep(i, 0, n) if(a[i] != b[i]) diff.push_back(i);
	if(sz(diff) % 2 != 0) {
		cout << "-1\n";
		return;
	}
	if(sz(diff) == 0) {
		cout << "0\n";
		return;
	}
	vector<int> seg;
	rep(i, 0, sz(diff)-1) seg.push_back(diff[i+1] - diff[i]);
	
	int ans = 0;
	vector<vector<int> > dp(sz(seg), vector<int>(sz(diff), 1e18));
	rep(i, 0, sz(seg)) dp[i][0] = 0;
	dp[0][1] = seg[0] * x;
	rep(i, 1, sz(seg)) {
		rep(j, 1, sz(seg)+1) {
			dp[i][j] = min(dp[i][j], dp[i-1][j]);
		}
		if(i > 1 && seg[i]*x < y) {
			rep(j, 1, sz(seg)+1) {
				dp[i][j] = min(dp[i][j], dp[i-2][j-1] + seg[i]*x);
			}
		}
	}

	ans = 1e18;
	rep(i, 0, sz(seg)+1) {
		ans = min(ans, dp[sz(seg)-1][i] + y*(sz(diff)-i*2)/2);
	}


	cout << ans << endl;

}

signed main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		// cout << "Case " << i << ": ";
		solve();
	}
}
