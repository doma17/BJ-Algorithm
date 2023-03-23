#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 100000
typedef long long int ll;

// 백준 13911번 문제

int V, E;
int u, v, w;
int M, x;
vector<int> mac;
int S, y;
vector<int> star;
priority_queue<int> pq;
vector<pair<int, int>> edge[10001];

void dijkstra() {
    
}

int main() {
	fastio;
    // INPUT
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
    }
    int input;
    // 맥도날드
    cin >> M >> x;
    for(int i = 0; i < M; i++) {
        cin >> input;
        mac.push_back(input);
    }
    // 스타벅스
    cin >> S >> y;
    for(int i = 0; i < S; i++) {
        cin >> input;
        star.push_back(input);
    }
    dijkstra();
}