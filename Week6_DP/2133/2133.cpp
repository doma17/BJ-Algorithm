#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int d[31];

int dp(int x) {
    // 점화식 : dp[n] = 3 * dp[n-2] + 2 * (dp[n-4] + dp[n-6] + ...)
    if(x == 0) return 1;
    if(x == 1) return 0;
    if(x == 2) return 3;
    if(d[x] != 0) return d[x];
    int result = 3 * dp(x - 2);
    for(int i = 3; i <= x; i++) {
        if(i % 2 == 0) {
            result += 2 * dp(x - i);
        }
    }
    return d[x] = result;
}

int main() {
    fastio;
    int N;
    cin >> N;
    cout << dp(N) << "\n";
}