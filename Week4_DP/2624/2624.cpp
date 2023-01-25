#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int T, k;
    cin >> T >> k;
    int coin[k][2];
    for(int i = 0; i < k; i++) cin >> coin[i][0] >> coin[i][1];

    int dp[10001] = {0}; dp[0] = 1;
    for(int i = 0; i < k; i++) {
        int coin_val = coin[i][0];
        int coin_cnt = coin[i][1];

        // 인덱스 1부터 dp를 계산하게 되면 중복으로 값이 들어가기 때문에 T에서 부터 1씩 내려온다.
        for(int j = T; j >= 0; j--) {
            for(int p = 1; p <= coin_cnt && j - coin_val * p >= 0; p++) {
                dp[j] += dp[j - coin_val * k];
            }
        }
    }
    cout << dp[T] << "\n";
}