#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long

void solve() {
	int l, r;
	cin >> l >> r;
	int n = r - l + 1;
	int ans = n*(n-1)*(n-2)/6;
	for(int i = l; i <= r; i++) {
		int cnt = 0;
		for(int j = 1; j <= sqrt(i); j++) if(i % j == 0) {
			int a = j, b = i / j;
			if(a == b) {
				if(a >= l && a < i) cnt++;
			} else {
				if(a >= l && a < i) cnt++;
				if(b >= l && b < i) cnt++;
			}
		}
		ans -= cnt * (cnt-1) / 2;
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
