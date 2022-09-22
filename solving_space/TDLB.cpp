#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long

const int maxn = 1e3+50;
int d[maxn][maxn]{};
void solve() {
	int n, m, t;
	cin >> n >> m >> t;
	memset(d, -1, sizeof(d));
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		d[u-1][v-1] = w;
		d[v-1][u-1] = w;
	}

	for(int k = 0; k < n; k++)
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(d[i][k]!= -1 && d[k][j] != -1) {
				if(d[i][j] == -1) d[i][j] = d[i][k] + d[k][j];
				else d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}

	}
	int ans = d[0][n-1];;
	while(t--) {
		int i, j;
		cin >> i >> j;
		i--, j--;
			if(d[0][i] != -1 && d[j][n-1] != -1) {
				if(ans == -1) ans = d[0][i] + d[j][n-1];
				else ans = min(ans, d[0][i] + d[j][n-1]);
			}
	}

	cout << ans << endl;
	

}

signed main() {
	solve();
}
