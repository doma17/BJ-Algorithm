#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
#define INF 987654321
#define MAX 10001

// 백준 1826번 문제
// https://www.acmicpc.net/problem/1826

// DEFINITION
int N;
pair<int, int> station[MAX];
priority_queue<int, vector<int>, less<int> > pq;
int L, P, cnt;

int main() {
	fastio;
    // INPUT
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        station[i].first = a;
        station[i].second = b;
    }
    cin >> L >> P;

    // PROCESS
    sort(station, station + N);

    int idx = 0;
    while(P < L) {
        while(station[idx].first <= P && idx < N) { // 현재 가진 연료 안에서 갈 수 있는 주유소를 탐색
            pq.push(station[idx++].second);
        }
        
        if(!pq.empty()) { // 가지고 있는 거리 안에서 가장 많이 연료를 가진 주유소를 방문
            P += pq.top(); pq.pop();
            cnt++;
        }

        if(idx == N || station[idx].first > P) { // 모든 주유소를 방문해도 도착하지 못했을 때
            cnt = -1;
            break;
        }
    }

    // OUTPUT
    cout << cnt << "\n";

    return 0;
}