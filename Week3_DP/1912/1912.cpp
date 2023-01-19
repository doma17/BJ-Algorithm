#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    int n;
    cin >> n;
    int num[n];
    for(int i = 0; i < n; i++) cin >> num[i];

    int dp[n];
    dp[0] = num[0];
    int maxValue = num[0];
    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + num[i], num[i]);
        maxValue = max(maxValue, dp[i]);
    }
    cout << maxValue << "\n";
}