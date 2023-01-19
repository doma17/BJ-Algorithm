#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    int n;
    cin >> n;
    int dp[500][500] = {0, };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> dp[i][j];
        }
    }

    for(int i = n-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            dp[i-1][j] += max(dp[i][j], dp[i][j+1]);
        }
    }
    cout << dp[0][0] << "\n";
}