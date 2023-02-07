#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int N;
int dp[31];

int main() {
    fastio;
    // INIT
    cin >> N;
    dp[0] = 1; dp[1] = 1; dp[2] = 3;
    // DP
    for(int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }
    // OUTPUT 
    if(N % 2) // 홀수일 경우 중간에 세로 막대기 하나를 중심으로 좌우 대칭만 존재한다.
        cout << (dp[N] + dp[N / 2]) / 2 << "\n";
    else // 짝수일 경우 중복의 가능성은 홀수에서 추가로 중간에 2x2가 있을 때가 있다.
        cout << (dp[N] + dp[N / 2] + 2 * dp[(N - 2) / 2]) / 2 << "\n";
                                    // 2x2와, 1x2가 두개인 경우가 있기 때문에 2를 곱해준다.
}