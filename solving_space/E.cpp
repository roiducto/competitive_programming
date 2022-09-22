#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long
int extgcd(int a, int b, int& x, int& y) {
    int gcd = a;
    if (b != 0) {
        gcd = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else {
        x = 1; y = 0;
    }
    return gcd;
}

bool Indefinite_equation(int a, int b, int n, int& x, int& y) {    //求一組特解
    int gcd = extgcd(a, b, x, y);       
    if (n % gcd) return false;
    int k = n / gcd;
    x *= k;
    y *= k;
    return true;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	int suma = 0;
	rep(i, 0, n) {
		int a, b;
		cin >> a >> b;
		suma += a;
		v[i] = b-a;
	}
	sort(v.rbegin(), v.rend());
	int up = 0; // b 最多up個
	rep(i, 0, n) if(v[i] < 0) {
		up = i+1;
		break;
	}
	
	rep(i, 1, n) v[i] += v[i-1];

	// xa, yb -> suma + v[x-1]
	int q;
	cin >> q;
	while(q--) {
		int a, b;
		cin >> a >> b;
		int x = 0, y = 0;
		if(Indefinite_equation(a, b, n, x, y)) {
			int k = n * a /__gcd(a, b);
			y += (up-y)/k*k;
			cout << suma + v[y-1] << endl;

		} else {
			cout << "-1\n";
		}
	}


}

signed main() {
	solve();
}
