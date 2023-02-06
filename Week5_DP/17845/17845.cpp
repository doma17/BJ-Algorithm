#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n, k;
int value[1001], cost[1001];
int dp[100000001] = {0};

int main() {
    fastio;

    cin >> n >> k;
    for(int i = 1; i <= k; i++)
        cin >> value[i] >> cost[i];
    
    for(int i = 1; i <= k; i++) {
        for(int j = cost[i]; j <= n; j++) {
            dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
        if(i % 10 == 0) cout << "\n";
    } 
    cout << dp[n] << "\n";
}