#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    int coin[n]; int dp[10001];
    for(int i = 0; i < n; i++) cin >> coin[i];
    for(int i = 0; i <= k; i++) dp[i] = 100001;
    

    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = coin[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }
    if(dp[k] == 100001) cout << "-1\n";
    else cout << dp[k] << "\n";
}