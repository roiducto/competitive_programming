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
	cin >> n >> x >> y;;
	string a, b;
	cin >> a >> b;
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

signed main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		// cout << "Case " << i << ": ";
		solve();
	}
}
