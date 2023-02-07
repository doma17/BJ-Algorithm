#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int T;
    cin >> T;
    while(T--) {
        // INIT
        int N, M;
        int coin[21];
        int dp[10001] = {0};
        dp[0] = 1;

        // INPUT
        cin >> N;
        for(int i = 1; i <= N; i++)
            cin >> coin[i];
        cin >> M;
        
        // DP
        for(int i = 1; i <= N; i++) {
            for(int j = coin[i]; j <= M; j++) {
                dp[j] += dp[j - coin[i]];
                cout << dp[j] << " ";
            }
            cout << "\n";
        }

        // OUTPUT
        cout << dp[M] << "\n";
    }
}