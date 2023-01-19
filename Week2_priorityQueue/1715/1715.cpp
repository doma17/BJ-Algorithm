#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    priority_queue<int, vector<int>, greater<>> q;
    int N, input;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> input;
        q.push(input);
    }

    int A, B, result = 0;
    while(true) {
        A = q.top();
        q.pop();
        if(q.empty()) break;
        B = q.top();
        q.pop();

        result += A + B;
        q.push(A + B);
    }
    cout << result << "\n";
}