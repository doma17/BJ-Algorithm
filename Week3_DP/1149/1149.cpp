#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    int n;
    cin >> n;

    int dp[n+1][3]; int cost[3];
    // index가 0일떄의 초기값 설정
    for(int i = 0; i < 3; i++) dp[0][i] = 0;

    for(int i = 1; i <= n; i++) {
        cin >> cost[0] >> cost[1] >> cost[2];
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + cost[2];
    }
    cout << min(dp[n][2], min(dp[n][0], dp[n][1]));
}