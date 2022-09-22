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
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i, 0, n) cin >> v[i];
	if(v[0] % 2 == 1) {
		int l = 0;
		while(l < n && v[l] % 2 == 1) l++;
		if(l == n) {
			cout << n-1 << endl;
			for(int i = 1; i <= n-1; i++) cout << i << ' ' << n << endl;
		} else {
			vector<pii> ans;
			for(int i = l+1; i < n; i++) if(v[i] % 2 == 1) {
				ans.push_back({l, i});
				ans.push_back({l-1, i});
			}
			ans.push_back({l-1, l});
			for(int i = 0; i < l-1; i++) ans.push_back({i, l-1});
			cout << ans.size() << endl;
			for(auto [L, r] : ans) cout << L+1 << ' ' << r+1 << endl;
		}
	} else if(v[0] % 2 == 0) {
		int l = 0;
		while(l < n && v[l] % 2 == 0) l++;
		if(l == n) {
			cout << n-1 << endl;
			for(int i = 1; i <= n-1; i++) cout << i << ' ' << n << endl;
		} else {
			vector<pii> ans;
			for(int i = l+1; i < n; i++) if(v[i] % 2 == 0) {
				ans.push_back({l, i});
				ans.push_back({l-1, i});
			}
			ans.push_back({l-1, l});
			for(int i = 0; i < l-1; i++) ans.push_back({i, l-1});
			cout << ans.size() << endl;
			for(auto [L, r] : ans) cout << L+1 << ' ' << r+1 << endl;
		}
	}
}

signed main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		// cout << "Case " << i << ": ";
		solve();
	}
}
