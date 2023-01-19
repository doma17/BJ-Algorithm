#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int N, input;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N >> input;
    pq.push(input);
    for(int i = 0; i < N * N - 1; i++) {
        cin >> input;
        pq.push(input);
        if(pq.size() > N) pq.pop();
    }
    cout << pq.top() << "\n";
}