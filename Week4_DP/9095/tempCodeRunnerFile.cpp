#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    int T, n;
    cin >> T;

    int dp[11] = {0, 1, 2, 4};
    for(int i = 4; i < 11; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-2];
    while(T--) {
        cin >> n;
        cout << dp[n] << "\n";
    }
}