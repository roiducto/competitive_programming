#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

const int mod = 1e9+7;

void solve2(string a, string b) {
	int n = b.length();
	int ansa = 0, ansb = 1;
	for(int i = 0; i < a.length(); i++) {
		int cnt = 0;
		for(int r = i; r < a.length() && a[r] == b[0]; r++) {
			cnt++;
			i = r;
		}
		if(cnt >= b.length()) {
			int k = 0;
			while(cnt > k*n+(k+1)*(n-1))k++;
			ansa += k;
			int d = cnt - k * (int)b.length();
			int va = k + 1;
			vector<int> dp(d+1);
			dp[0] = 1;
			queue<int> q;
			int sum = 0;
			for(int j = 0; j < va; j++)
			for(int i = d, id = d; i >= 0; i--) {
				while(id >= 0 && q.size() < n) {
					sum += dp[id];
					q.push(dp[id]);
					id--;
				}
				dp[i] = sum % mod;
				sum -= q.front();
				q.pop();
			}
			ansb *= dp[d];
		}
	}
	cout << ansa << ' ' << ansb << endl;
}

void solve() {
	string a, b;
	cin >> a >> b;
	bool same = true;
	for(int i = 0; i < b.length(); i++) if(b[i] != b[0]) same = false;
	if(same) {
		solve2(a, b);
		return;
	}
	string p = b + "$" + a;
	vector<int> pi = prefix_function(p);
	int ans = 1;
	int cnt = 0;
	vector<pii> v;
	for(int i = 0; i < (int)p.length(); i++) if(pi[i] == b.length()) {
		int l = i, r = i;
		for(int j = i; j > i - b.length(); j--) if(pi[j] == b.length()) l = j - b.length() + 1;
		for(int j = i; j < i + b.length(); j++) if(pi[j] == b.length()) r = j;
		v.push_back({l, r});
	}

	sort(all(v), [](pii ta, pii tb) {
			if(ta.first == tb.first) return ta.second > tb.second;
			return ta.first < tb.first;
	});
	if(v.size() == 0) {
		cout << "0 1\n";
		return;
	}
	int ansa = 0, ansb = 1;
	cnt = 0;
	int l = v[0].first, r = v[0].second;
	for(auto [x, y] : v) {
		if(l == x && r  == y) {
			cnt++;
		} else if(x > r) {
			ansa++;
			ansb = (ansb * cnt) % mod;
			cnt = 1;
			l = x, r = y;
		}
	}
	if(cnt) {
		ansa++;
		ansb = (ansb * cnt) % mod;
	}
	cout << ansa << ' ' << ansb << endl;

}

signed main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		// cout << "Case " << i << ": ";
		solve();
	}
}
