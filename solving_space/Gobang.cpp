#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long
string s[6];
bool check() { // 不能有五顆連在一起
	rep(i, 0, 5) rep(j, 0, 2) if(s[i][j] != 'X') { // 直線
		bool five = true;
		rep(k, 0, 5) if(s[i][j] != s[i][j+k]) five = false;
		if(five) return false;
	}

	rep(i, 0, 2) rep(j, 0, 5) if(s[i][j] != 'X') { // 橫線
		bool five = true;
		rep(k, 0, 5) if(s[i][j] != s[i+k][j]) five = false;
		if(five) return false;
	}

	rep(i, 0, 2) rep(j, 0, 2) if(s[i][j] != 'X') { // 左上->右下
		bool five = true;
		rep(k, 0, 5) if(s[i][j] != s[i+k][j+k]) five = false;
		if(five) return false;
	}

	rep(i, 4, 6) rep(j, 0, 2) if(s[i][j] != 'X') { // 左下->右上
		bool five = true;
		rep(k, 0, 5) if(s[i][j] != s[i-k][j+k]) five = false;
		if(five) return false;
	}
	return true;
}
void solve() {
	rep(i, 0, 6) cin >> s[i];
	int cnt_W = 0, cnt_B = 0;
	rep(i, 0, 6) for(char c : s[i]) {
		cnt_W += (c == 'W');
		cnt_B += (c == 'B');
	}
	bool ans = false;
	if(cnt_B == cnt_W) {
		ans |= check();
		rep(i, 0, 6) rep(j, 0, 6) if(s[i][j] == 'W') {
			s[i][j] = 'X';
			ans |= check();
			s[i][j] = 'W';
		}
	} else if(cnt_B == cnt_W + 1) {
		ans |= check();
		rep(i, 0, 6) rep(j, 0, 6) if(s[i][j] == 'B') {
			s[i][j] = 'X';
			ans |= check();
			s[i][j] = 'B';
		}
	}
	cout << (ans ? 'Y' : 'N') << endl;

}

signed main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		solve();
	}
}
