#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int n, t;
    // k: 단원 별 예상 공부 시간, s: 문제 배점
    int k[1001], s[1001];
    int dp[10001] = {0};
    
    cin >> n >> t;
    for(int i = 1; i <= n; i++) cin >> k[i] >> s[i];

    for(int i = 1; i <= n; i++) {
        for(int j = t; j >= 1; j--) {
            if(j - k[i] > 0) dp[j] = max(dp[j], dp[j - k[i]] + s[i]);
            dp[j] = max(dp[j], dp[j-1]);
        }
    }
    cout << dp[t] << "\n";
}