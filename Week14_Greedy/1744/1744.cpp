#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
#define INF 987654321
#define MAX 1000001

int main() {
	fastio;
    // DEFINITION
    int N, zero_cnt = 0;
    priority_queue<ll> pq; // 양수만 가지는 큐
    priority_queue<ll, vector<ll>, greater<> > pq_n; // 음수만 가지는 큐
    ll ans = 0;

    // INPUT
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x > 0) 
            pq.push(x);
        else if (x < 0)
            pq_n.push(x);
        else
            zero_cnt++;
    }

    // 양수만 포함하는 수
    while(!pq.empty()) {
        int a = pq.top(); pq.pop(); // 가장 큰 양수부터 출력

        if(pq.empty()) { // 홀수로 남은 숫자이면 정답에 추가 후 종료
            ans += a;
            break;
        }
        int b = pq.top(); pq.pop();

        ll sum = a + b;
        ll multi = a * b;

        // 곱해서 더하는 것과, 두 요소를 각각 더하는 것이 큰지 작은지 비교하여 더한다.
        ans += (sum > multi ? sum : multi);
    }

    // 음수만 포함하는 수 
    while(!pq_n.empty()) {
        int a = pq_n.top(); pq_n.pop(); // 가장 작은 음수부터 출력

        // 홀수로 남은 숫자이면 0에 곱하거나 or 정답에 추가후 종료
        if(pq_n.empty()) { 
            if(zero_cnt <= 0) // 남은 0 요소가 없다면 그냥 ans 변수에 더하기
                ans += a; 
            else // 남은 0 요소가 있으므로 0 요소 하나를 제거
                zero_cnt--; 
            break;
        }
        int b = pq_n.top(); pq_n.pop();

        ll sum = a + b;
        ll multi = a * b;

        ans += (sum > multi ? sum : multi);
    }

    // OUTPUT
    cout << ans << "\n";
    return 0;
}