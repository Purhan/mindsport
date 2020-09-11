#include <bits/stdc++.h>
using namespace std;
#define fo(int, i, a, b)        for (int i=a; i<(b); i++)
#define forev(int, i, b, a)     for (int i = (b)-1; i >= a; i--)
#define uns                     unsigned
#define lli                     long long int
#define ld                      long double
#define all(x)                  x.begin(), x.end()
#define sortall(x)              sort(all(x))
#define enl                     "\n"
#define dbg(x)                  cout << #x << ": " << x << enl;
// #define PI 3.1415926535897932384626
// const int MOD = 1000000007; const lli INF = 1e18; const int MX = 100001;

void solve() {
    lli n; cin >> n;
    vector<lli> v(n);
    fo(lli, i, 0, n) {
        cin >> v[i];
    }

    lli sum = 0, prevsum = 0, a = 0, b = 0, moves = 0;
    lli l = 0, r = n - 1;

    while (l <= r) {
        moves++;
        if (moves & 1) {
            while (l <= r && sum <= prevsum) {
                sum += v[l];
                l++;
            }
            prevsum = sum;
            a += prevsum;
            sum = 0;
        } else {
            while (l <= r && sum <= prevsum) {
                sum += v[r];
                r--;
            }
            prevsum = sum;
            b += prevsum;
            sum = 0;
        }
    }

    cout << moves << ' ' << a << ' ' << b << enl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testcase; cin >> testcase; for (int i = 1; i <= testcase; ++i)
        solve();
    return 0;
}