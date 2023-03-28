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

int N, E;
int a, b, c;
int v1, v2;
vector<pair<int, int> > edge[801];
priority_queue<pair<int, int>> q;
ll dist[801];

ll dijkstra(int start, int end) {
    // 전처리
    for(int i = 0; i <= N; i++) 
		dist[i] = INF;
    dist[start] = 0;
    q.push({0, start});

    while(!q.empty()) {
        int now = q.top().second;
        int bCost = -q.top().first;
        q.pop();

        for(auto e : edge[now]) {
            int next = e.first;
            int nCost = e.second;

            if( dist[next] > bCost + nCost) {
                dist[next] = bCost + nCost;
                q.push({-(bCost + nCost), next});
            }
        }
    }

    if(start == end) return 0;
    if(dist[end] == INF) return -1; 
    return dist[end];
}

int main() {
	fastio;
    cin >> N >> E;
    for(int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    int result1, result2;
    int x1 = dijkstra(1, v1);
    int x2 = dijkstra(v1, v2);
    int x3 = dijkstra(v2, N);
    if(x1 < 0 || x2 < 0 || x3 < 0) result1 = INF;
    else result1 = x1 + x2 + x3;

    int y1 = dijkstra(1, v1);
    int y2 = dijkstra(v1, v2);
    int y3 = dijkstra(v2, N);
    if(y1 < 0 || y2 < 0 || y3 < 0) result2 = INF;
    else result2 = y1 + y2 + y3;

    int ans = min(result1, result2);
    if(ans == INF) cout << "-1\n";
    else cout << ans << "\n";
}