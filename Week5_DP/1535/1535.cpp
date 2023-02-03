#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int n;
    int L[21], J[21];
    int dp[101] = {0};

    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> L[i];
    for(int i = 1; i <= n; i++)
        cin >> J[i];

    for(int i = 1; i <= n; i++) {
        for(int j = 100; j >= L[i]; j--) {
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
        }
    }
    cout << dp[99] << "\n";
}