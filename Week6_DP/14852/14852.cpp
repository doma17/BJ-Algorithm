#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

ll d[1000001][2];

ll dp(int x) {
    // 점화식 : dp[n] = 2 * dp[n-1] + 3 * dp[n-2] + 2 * (dp[n-3] + dp[n-4] + ...)
    d[0][0] = 0;
    d[1][0] = 2;
    d[2][0] = 7;
    d[2][1] = 1;
    for(int i = 3; i <= x; i++) {
        d[i][1] = (d[i - 1][1] + d[i -3][0]) % 1000000007;
        d[i][0] = (3 * d[i - 2][0] + 2 * d[i-1][0] + 2 * d[i][1]) % 1000000007;
    }
    return d[x][0];
}

int main() {
    fastio;
    int N;
    cin >> N;
    cout << dp(N) << "\n";
}