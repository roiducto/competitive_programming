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
	int n, k;
	cin >> n >> k;
	vector<int> v(k);
	rep(i, 0, n) {
		int in; cin >> in;
		v[i%k] = max(v[i%k], in);
	}

	cout << accumulate(all(v), 0ll) << endl;
}

signed main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		// cout << "Case " << i << ": ";
		solve();
	}
}
