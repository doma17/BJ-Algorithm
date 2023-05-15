#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
#define INF 987654321
#define MAX 10001

// 백준 2212번 문제
// https://www.acmicpc.net/problem/2212

// DEFINITION
int N, K;
int sensor[MAX];
int sum[MAX];
int ans;

int main() {
	fastio;
    // INPUT
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> sensor[i];
    }

    // PROCESS
    sort(sensor, sensor + N);
    for(int i = 0; i < N-1; i++) {
        sum[i] = sensor[i + 1] - sensor[i];
    }

    sort(sum, sum + N-1);
    for(int i = 0; i < N - K; i++) {
        ans += sum[i];
    }
    
    // OUTPUT
    cout << ans << "\n";

    return 0;
}