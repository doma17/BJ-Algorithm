#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// N:현재 활성화 된 앱 수, M:필요한 메모리 바이트
int N, M;
// m[]:앱당 사용중인 메모리, c[]:앱 비활성화 비용
int m[101], c[101];
// dp[]:해당 메모리 바이트에서의 최소 비용
int dp[101][10001] = {0};
int sum = 0;

int main() {
    fastio;
    // Input
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        cin >> m[i];
    for(int i = 1; i <= N; i++) {
        cin >> c[i];
        sum += c[i];
        // 모든 앱을 종료 시켰을 때의 최대 비용을 구해서
        // dp 계산시 최대 인덱스로 사용한다.
    }

    // DP
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= sum; j++) {
            if(j - c[i] >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - c[i]] + m[i]);
            else
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }

    // Find Value
    for(int i = 1; i <= sum; i++) {
        if(dp[N][i] >= M) {
            cout << i << "\n";
            break;
        }
    }
}