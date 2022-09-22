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
	if(n == 1) {
		cout << "0\n";
		return;
	}
	if(v[0] % 2 != v[n-1] % 2) v[n-1]++;
	if(v[0] % 2 == 1 && v[n-1] % 2 == 1) {
		cout << n-1 << endl;
		cout << 1 << ' ' << n << endl;
		for(int i = 1; i < n-1; i++) {
			if(v[i] % 2 == 0) {
				cout << "1 " << i+1 << endl;
			} else {
				cout << i+1 << ' ' << n << endl;
			}
		}
	} else if(v[0] % 2 == 0 && v[n-1] % 2 == 0) {
		cout << n-1 << endl;
		cout << 1 << ' ' << n << endl;
		for(int i = 1; i < n-1; i++) {
			if(v[i] % 2 == 1) {
				cout << "1 " << i+1 << endl;
			} else {
				cout << i+1 << ' ' << n << endl;
			}
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
