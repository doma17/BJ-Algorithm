#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// n:사탕 종류, m:돈
int n, m;
// 칼로리, 가격
int calorie[5001]; int price[5001];
// 100.00 -> 10000
int dp[10001] = {0};

int main() {
    fastio;
    double temp;
    while(true) {
        // INPUT
        cin >> n >> temp;
        m = (int)(temp * 100 + 0.5); // 소숫 값을 정수형으로 바꾼다.
        if(n == 0 && m == 0) break;
        
        for(int i = 1; i <= n; i++) {
            cin >> calorie[i] >> temp;
            price[i] = (int)(temp * 100 + 0.5); // 소숫 값을 정수형으로 바꾼다.
        }

        // DP
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(i - price[j] >= 0)
                    dp[i] = max(dp[i], dp[i - price[j]] + calorie[j]);
            }
        }

        // OUTPUT
        int MAX = 0;
        for(int i = 1; i <= m; i++) {
            MAX = max(MAX, dp[i]);
        }
        cout << MAX << "\n";
    }
}