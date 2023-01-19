#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    int N, M, input;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> input;
        pq.push(input);
    }

    ll a, b;
    for(int i = 0; i < M; i++) {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();

        // 더한 값을 덮어쓴다.
        a = a + b;

        pq.push(a);
        pq.push(a);
    }

    ll sum = 0;
    while(!pq.empty()) {
        sum += pq.top(); pq.pop();
    }
    cout << sum << "\n";
}