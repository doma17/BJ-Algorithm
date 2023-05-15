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
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int> > pq;
bool visited[MAX];
int L, P;
int cnt = 0;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

int main() {
	fastio;
    // INPUT
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    cin >> L >> P;

    // PROCESS
    sort(v.begin(), v.end(), cmp);

    int idx = 0;
    while(P < L) {
        while(idx < N && v[idx].first <= P) {
            P += v[idx].second;
            idx++;
            cnt++;
            break;
        }
        for(int i = 0; i < v.size(); i++) {
            if(v[i].first <= P && visited[i] == false) {
                P += v[i].second; // 기름 추가
                visited[i] = true; // 방문 주유소 체크
                cnt++;
                break;
            }
        }

        if(v.empty()) { // 모든 주유소를 방문해도 도착하지 못했을 때
            cnt = -1;
            break;
        }
    }

    // OUTPUT
    cout << cnt << "\n";

    return 0;
}