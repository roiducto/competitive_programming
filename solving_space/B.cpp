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
	int n, x, y;
	cin >> n >> x >> y;
	if(x == 0 && y == 0) cout << "-1\n";
	else if(x == 0) {
		if((n-1) % y == 0) {
			vector<int> ans;
			for(int i = n - y+1; i > 1; i -= y)
				for(int j = 0; j < y; j++) ans.push_back(i);
			reverse(all(ans));
			for(int t : ans) cout << t << ' ';
			cout << endl;
			
		} else {
			cout << "-1\n";
		}
	} else if(y == 0) {
		if((n-1) % x == 0) {
			vector<int> ans;
			for(int i = n - x+1; i > 1; i -= x)
				for(int j = 0; j < x; j++) ans.push_back(i);
			reverse(all(ans));
			for(int t : ans) cout << t << ' ';
			cout << endl;
			
		} else {
			cout << "-1\n";
		}
	} else {
		cout << "-1\n";
	}
}

signed main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		// cout << "Case " << i << ": ";
		solve();
	}
}
