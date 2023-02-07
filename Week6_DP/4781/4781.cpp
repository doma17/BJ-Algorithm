#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

// n:사탕 종류, m:돈
int n; double m;
// 칼로리, 가격
int calorie[5001] = {0}; double price[5001] = {0};
// 100.00 -> 10000
int dp[10001] = {0};

int main() {
    fastio;
    while(true) {
        // INPUT
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;
        for(int i = 1; i <= n; i++)
            cin >> calorie[i] >> price[i];

        // DP
        int ans = 0;
        // rounding error 때문에 0.5를 더해준다. (temp * 100 + 0.5)
        for(int i = 1; i <= m * 100 + 0.5; i++) { 
            for(int j = 1; j <= n; j++) { 
                if(i - price[j] * 100 + 0.5 >= 0)
                    dp[i] = max(dp[i], dp[i - (int)(price[j] * 100 + 0.5)] + calorie[j]);
            }
            ans = max(ans, dp[i]);
        }

        // OUTPUT
        cout << ans << "\n";
    }
}