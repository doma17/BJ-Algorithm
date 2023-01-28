#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    ll dp[100001][3] = {0};
    dp[0][1] = 0; dp[0][2] = 1;
    dp[1][1] = 1; dp[1][2] = 0;
    dp[2][1] = 1; dp[2][2] = 1;
    for(int i = 3; i < 100000; i++) {
        dp[i][1] = (dp[i-1][2] + dp[i-2][2] + dp[i-3][2]) % 1000000009;
        dp[i][2] = (dp[i-1][1] + dp[i-2][1] + dp[i-3][1]) % 1000000009;
    }

    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n][1] << " " << dp[n][2] << "\n";
    }
}