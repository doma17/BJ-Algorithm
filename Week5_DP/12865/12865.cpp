#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n, k;
int dp[101][100001];
int w[101];
int v[101];

int main() {
    fastio;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            // 0-1 Knapsack Problem
            if(j - w[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k] << "\n";
}