#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int n, m;
    int day[21], page[21];
    int dp[21][201] = {0};

    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> day[i] >> page[i];
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(j - day[i] >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - day[i]] + page[i]);
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
        }
    }
    cout << dp[m][n] << "\n";
}