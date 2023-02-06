#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int c, n;
    int value[21], cust[21];
    // c명의 고객을 늘리기 위한 돈의 최솟값
    int dp[100001] = {0};

    cin >> c >> n;
    for(int i = 1; i <= n; i++)
        cin >> value[i] >> cust[i];

    for(int i = 1; i <= n; i++) {
        for(int j = value[i]; j <= 100000; j++) {
            dp[j] = max(dp[j], dp[j - value[i]] + cust[i]);
        }
    }
    
    for(int i = 1; i <= 100000; i++) {
        if(dp[i] >= c) {
            cout << i << "\n";
            break;
        }
    }
}