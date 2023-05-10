#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
#define INF 987654321
#define MAX 1000001

// 백준 13975번 문제 
// https://www.acmicpc.net/problem/13975

int main() {
	fastio;
    // DEFINITION
    int T, K;
    priority_queue<ll, vector<ll>, greater<ll> > pq;

    // TEST CASE
    cin >> T;
    while(T--) {
        // INPUT
        cin >> K;
        for(int i = 0; i < K; i++) {
            int x;
            cin >> x;
            pq.push(x);
        }

        // PROCESS
        ll ans = 0;
        while(!pq.empty()) {
            ll sum = 0;
            sum += pq.top(); pq.pop(); // 첫 번째로 작은 파일
            sum += pq.top(); pq.pop(); // 두 번째로 작은 파일

            ans += sum;
            // 큐가 비어있다면 최종 종합 파일이기 때문에 큐에 추가할 필요없다.
            if(!pq.empty()) 
                pq.push(sum);
        }
        cout << ans << "\n";
    }
    return 0;
}