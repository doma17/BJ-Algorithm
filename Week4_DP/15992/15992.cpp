#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    int T, n, m, MOD = 1000000009;
    cin >> T;

    ll dp[1001][1001] = {};
    dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
    dp[2][1] = 1; dp[2][2] = 1; dp[2][3] = 0;
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
    for(int i = 4; i <= 1000; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1]) % MOD + (dp[i-3][j-1]) % MOD;
        }
        dp[i][i] = 0;
    }

    while(T--) {
        cin >> n >> m;
        cout << dp[n][m] % MOD << "\n";
    }
}