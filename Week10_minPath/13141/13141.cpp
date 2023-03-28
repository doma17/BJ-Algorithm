#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321

// 백준 13141번 문제
// 아이디어1. 노드의 길이만큼 더미 노드를 생성해서 계산한다.
// 아이디어2. 다익스트라 알고리즘으로 해당 노드에 결국 최초로 불이 붙는 시간을 계산하고
//          그를 통해, 출발 노드에서부터 타들어 갔을 때부터 해당 간선이 다 탔을 때의 시간을 구하고
//          그 중 가장 오래된 시간이 해당 출발노드에서 부터 전부 탔을 때의 시간이다.
//          이 과정을 모든 노드에서 하고 최솟값을 구하면 된다.
//
// 설명: 처음 아이디어1로 시작해 보았으나, 소숫점으로 숫자를 출력하는 부분과 처리속도 문제가 발생하여
// 아이디어2로 해보았습니다.

int n, m;
int s, e, l;
vector<pair<int, int>> edge[201];
int dist[201];
bool visited[201];

// 다익스트라 알고리즘을 통해서 해당 노드에 불이 언제 도착하는지를 계산
void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(dist[now] < cost) continue;

        for(auto e : edge[now]) {
            int next = e.first;
            int nCost = e.second;

            if(dist[next] > cost + nCost) {
                dist[next] = cost + nCost;
                pq.push({-(cost + nCost), next});
            }
        }
    }
}

// 출발노드에서 부터 input으로 받은 두개 노드 사이의 간선이 다 타들어가는 최종시간
// 즉, 출발 ~ 간선이 전부 탄 시간을 계산하는 함수
double time_calc(int node1_time, int node2_time, int vertex) {
    double time;
    double length = vertex;
    for(time = 0; time < abs(node1_time - node2_time);) {
        length--;
        time++;
        if(time >= vertex) return time;
    }
    return (max(node1_time, node2_time) + (length / 2));
}

// 모든 간선을 방문하기 위한 bfs
double bfs(int start) {
    memset(visited, 0, sizeof(visited)); // visited 초기화
    double max_time = -1;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int a = q.front(); q.pop();
        if(visited[a]) continue;
        // 모든 노드가 아닌 모든 간선을 방문하는 것이 목표이다.
        visited[a] = true;

        for(auto e : edge[a]) { 
            // time_calc(현재노드의 도착시간, 다음노드의 도착시간, 간선의 길이)
            max_time = max(max_time, time_calc(dist[a], dist[e.first], e.second));         
            q.push(e.first);
        }
    }
    return max_time;
}

int main() {
	fastio;
    // INPUT
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> s >> e >> l;
        edge[s].push_back({e, l});
        edge[e].push_back({s, l});
    }

    // OUTPUT
    double min_time = INF;
    for(int i = 1; i <= n; i++) {
        dijkstra(i);
        min_time = min(min_time, bfs(i));
    }
    cout << fixed; cout.precision(1);
    cout << min_time << "\n";
}