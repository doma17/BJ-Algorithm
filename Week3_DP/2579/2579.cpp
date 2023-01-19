#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    int T; 
    cin >> T;

    int S[T];
    for(int i = 0; i < T; i++) cin >> S[i];

    int dp[T]; 
    dp[0] = S[0];
    dp[1] = max(S[0] + S[1], S[1]);
    dp[2] = max(S[0] + S[2], S[1] + S[2]);
    for(int i = 3; i < T; i++) {
        dp[i] = max(dp[i-2] + S[i], S[i-1] + S[i] + dp[i-3]);
    }
    cout << dp[T-1] << "\n";
}