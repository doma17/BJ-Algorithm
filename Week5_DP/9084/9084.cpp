#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int t, n, m;

    cin >> t;
    while(t--) {
        int coin[21];
        int dp[10001] = {0};
        dp[0] = 1;

        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> coin[i];
        
        cin >> m;
        for(int i = 1; i <= n; i++) {
            for(int j = coin[i]; j <= m; j++) {
                dp[j] += dp[j - coin[i]];
            }
        }
        cout << dp[m] << "\n";
    }
}