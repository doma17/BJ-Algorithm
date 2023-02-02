#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int n;
    int input[1001]; int dp[1001] = {0};
    stack<int> s; int ans = 0; int ans_index = -1;

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> input[i];
    // 이전 문제에서 사용한 최대 길이의 수열 찾기
    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
        for(int j = i - 1; j >= 1; j--) {
            if(input[i] > input[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(dp[i] > ans) {
            ans = dp[i];
            ans_index = i; // 최대 길이의 수열을 가지는 dp의 인덱스를 저장해 놓는다.
        }
    }
    // 스택을 이용해서 과거의 값을 찾는다.
    s.push(input[ans_index]);
    int cnt = ans_index;
    for(int i = ans_index - 1; i > 0; i--) {
        if(input[i] < input[cnt] && dp[i] + 1 == dp[cnt]) {
            cnt = i;
            s.push(input[i]);
        }
    }

    cout << ans << "\n";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}