#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 2100000000 // 21억
typedef long long int ll;

// 백준 1865번 문제
// 음수 가중치가 존재하지 않고, 최단거리를 푸는 문제이기 때문에 
// 다익스트라 알고리즘을 사용한다.

int V, E;
int start;
int u, v, w;
vector<pair<int, int> > edge[20001];
priority_queue<pair<int, int>> q;
ll dist[20001];

void dijkstra(int x) {
    dist[x] = 0;
    q.push({0, x});

    while(!q.empty()) {
        int now = q.top().second;
        int cost = -q.top().first;
        q.pop();

        // 이미 거리가 최솟값인 노드를 중복으로 계산할 필요 없기 때문에 생략한다.
        if(dist[now] < cost) continue;

        for(auto e : edge[now]) {
            int next = e.first;
            int nCost = e.second;

            if( dist[next] > cost + nCost) {
                dist[next] = cost + nCost;
                q.push({-(cost + nCost), next});
            }
        }
    }

    for(int i = 1; i <= V; i++) {
        if(dist[i] == INF) cout << "INF\n";
        else {
            cout << dist[i] << "\n";
        }
    }
}

int main() {
	fastio;

    cin >> V >> E >> start;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }
    for(int i = 0; i <= V; i++) 
		dist[i] = INF;
    dijkstra(start);
}