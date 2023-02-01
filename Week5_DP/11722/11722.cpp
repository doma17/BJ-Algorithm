#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int n;
    cin >> n;
    int input[1001]; int dp[1001] = {0};
    for(int i = 1; i <= n; i++) cin >> input[i];

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
        for(int j = i - 1; j >= 1; j--) {
            if(input[i] < input[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }
    cout << ans << "\n";
}