#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    int T, n, m; int num = 1000000009;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        ll dp[n+1][m+1];
        for(int i = 1; i <= 3; i++) {
            for(int j = 1; j <= m; j++){
                dp[i][j] = 0;
            }
        }

        dp[1][1] = 1;
        dp[2][1] = 1; dp[2][2] = 1;
        dp[3][1] = 1; dp[3][2] = 2; dp[3][3] = 1;
        dp[4][1] = 0;

        for(int i = 4; i <= n; i++) {
            for(int j = 2; j < i; j++) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1]) % num; 
            }
            dp[i][1] = 0;
            dp[i][i] = 1;
        }
        cout << dp[n][m] << "\n";
    }
}