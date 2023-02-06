#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// n:추의 개수, m:구슬 개수, max_marble:추의 최대 무게
int n, m, max_marble = 0;
// 추의 무게, 구슬의 무게
int weight[31], marble[8];
int dp[31][31 * 500 + 1] = {0};

int main() {
    fastio;

    // Input
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> weight[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> marble[i];
    
        
    // DP
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= max_marble; j++) {
            if(j - weight[i] >= 0)
                dp[j] = max(dp[j - 1], dp[j - weight[i]] + weight[i]);
            cout << dp[j] << " ";
        }
        cout << "\n";
    }

    // Result
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= max_marble; j++) {
            if(dp[j] == marble[i]) {
                cout << "Y ";
                break;
            }
            else if(j + 1 == max_marble) {
                cout << "N ";
                break;
            }
        }
    }
}