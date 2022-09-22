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
	int a = 2, b = 3, n = 13;
	int x = 0, y = 0;
	if(Indefinite_equation(a, b, n, x, y))
	cout << x << ' ' << y << endl;
	else cout << "NOO\n";

}

signed main() {
	solve();
}
