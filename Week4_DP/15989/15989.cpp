#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    int T, n, MOD = 1000000009;
    cin >> T;

    priority_queue<int> q;
    vector<int> v;
    while(T--) {
        cin >> n;
        q.push(n);
        v.push_back(n);
    }

    ll dp[q.top() + 1][3];
    dp[1][0] = 1;
    dp[2][0] = 1; dp[2][1] = 1;
    dp[3][0] = 1; dp[3][1] = 1; dp[3][2] = 1;
    for(int i = 4; i <= q.top(); ++i) {
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-2][0] + dp[i-2][1];
        dp[i][2] = dp[i-3][0] + dp[i-3][1] + dp[i-3][2];
    } 
    for(auto x : v) cout << dp[x][0] + dp[x][1] + dp[x][2] << "\n";
}