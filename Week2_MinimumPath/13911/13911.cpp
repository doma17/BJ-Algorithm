#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

// 백준 13911번 문제
// 가짜 노드를 활용한 방식으로 풀이.

int V, E;
int a, b, c;
int M, x;
int S, y;
vector<pair<int, int>> edge[10005];
int dist[10005][2];
bool visited[10005];

void dijkstra(int start, int index) {
    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});
    dist[start][index] = 0;

    while (!pq.empty()) {
        int now = pq.top().first;
        int totalCost = pq.top().second;
        pq.pop();

        for(auto x : edge[now]) {
            int next = x.first;
            int cost = x.second;

            if(cost + totalCost >= dist[next][index]) continue;

            dist[next][index] = cost + totalCost;
            pq.push({next, cost + totalCost});
        }   
    }
}

int main() {
	fastio;
    // INPUT
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    int input;
    // 맥도날드
    cin >> M >> x;
    for(int i = 0; i < M; i++) {
        cin >> input;
        edge[10001].push_back({input, 0});
        visited[input] = true;
    }
    // 스타벅스
    cin >> S >> y;
    for(int i = 0; i < S; i++) {
        cin >> input;
        edge[10002].push_back({input, 0});
        visited[input] = true;
    }
    memset(dist, INF, sizeof(dist));

    // 다익스트라
    dijkstra(10001, 0);
    dijkstra(10002, 1);

    // OUTPUT
    // 두 상점에서의 거리의 합이 최소인 노드를 찾는다.
    int min_dist = INF;
    for(int i = 1; i <= V; i++) {
        if(visited[i]) continue;
        if(dist[i][0] > x || dist[i][1] > y) continue;

        min_dist = min(min_dist, dist[i][0] + dist[i][1]);
    }

    if(min_dist == INF) cout << "-1\n";
    else cout << min_dist << "\n";
}