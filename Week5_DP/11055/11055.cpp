#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int n;
    cin >> n;
    int input[1001]; int dp[1001] = {0}; int sum[1001] = {0};
    for(int i = 1; i <= n; i++) cin >> input[i];

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = input[i];
        for(int j = 1; j < i; j++) {
            if(input[i] > input[j]) {
                dp[i] = max(dp[i], dp[j] + input[i]);
            }
        }
        ans = max(dp[i], ans);
    }
    cout << ans << "\n";
}