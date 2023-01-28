#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    int MOD = 1000000009;
    ll dp[1001][1001] = {0};
    dp[1][1] = 1; dp[2][1] = 1; dp[3][1] = 1;
    dp[2][2] = 1;
    for(int i = 3; i <= 1000; i++) {
        for(int j = 2; j <= i; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1]) % MOD;
        }
    }

    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int sum = 0;
        for(int i = 1; i <= m; i++) {
            sum = (sum + dp[n][i]) % MOD;
        }
        cout << sum << "\n";
    }
}