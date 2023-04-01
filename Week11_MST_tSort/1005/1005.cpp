#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

// 백준 1005번 문제
// 위상정렬을 통해서 풀이

int T, n, k;
int a, b;
int w;
vector<int> edge[1001];
int degree[1001];
int cost[1001];
int dist[1001];

void toplogical_sort() {
    queue<int> q;
    // 차수가 없는 노드는 cost자체가 건물을 짓는데 걸리는 시간이다.
    for(int i = 1; i <= n; i++) {
        if(degree[i] != 0) continue;

        q.push(i);
        dist[i] = cost[i];
    }

    // DAG 위상정렬
    while(!q.empty()) {
        int now = q.front(); q.pop();

        for(auto next : edge[now]) {
            degree[next]--;

            dist[next] = max(dist[next], dist[now] + cost[next]);
            if(degree[next] == 0) q.push(next);
        }
    }
}

void reset() {
    memset(edge, 0, sizeof(edge));
    memset(degree, 0, sizeof(degree));
    memset(cost, 0, sizeof(cost));
    memset(dist, 0, sizeof(dist));
}

int main() {
	fastio;
    cin >> T;
    while(T--) {
        // INPUT
        cin >> n >> k;
        for(int i = 1; i <= n; i++)
            cin >> cost[i];
        for(int i = 0; i < k; i++) {
            cin >> a >> b;
            edge[a].push_back(b);
            degree[b]++;
        }
        cin >> w;
        // Toplogical Sort
        toplogical_sort();
        // OUTPUT
        cout << dist[w] << "\n";
        // RESET
        reset();
    }
}