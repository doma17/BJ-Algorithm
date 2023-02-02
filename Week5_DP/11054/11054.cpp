#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int n;
    cin >> n;
    int input[1001]; int dp[1001] = {0}; int r_dp[1001] = {0};
    for(int i = 1; i <= n; i++) cin >> input[i];

    // 정방향으로 증가하는 수열의 최대 길이를 dp[]에 입력한다.
    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
        for(int j = 1; j <= i; j++) {
            if(input[i] > input[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    // 역방향으로 감소하는 수열의 최대 길이를 r_dp[]에 입력한다.
    for(int i = n; i >= 1; i--) {
        r_dp[i] = 1;
        for(int j = n; j >= i; j--) {
            if(input[i] > input[j]) {
                r_dp[i] = max(r_dp[i], r_dp[j] + 1);
            }
        }
    }
    // 정방향, 역방향 dp의 합이 가장 긴 바이토닉 부분 수열을 나타낸다.
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i] + r_dp[i] - 1); // -1을 빼주는 이유는 i인덱스의 길이가 중복되기 때문이다.
    }
    cout << ans << "\n";
}