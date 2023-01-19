#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    int n;
    cin >> n;
    int dp[n];
    dp[0] = 1;
    dp[1] = 3;
    for(int i = 2; i < n; i++) {
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
    }
    cout << dp[n-1] << "\n";
}