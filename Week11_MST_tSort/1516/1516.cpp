#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

// 백준 1516번 문제
// 위상정렬을 통해서 풀이

int n;
vector<int> edge[501];
int degree[501];
int cost[501];
int dist[501];
int input;

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

int main() {
	fastio;
    // INPUT
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
        while(true) {
            cin >> input;
            if(input == -1) break;
            edge[input].push_back(i);
            degree[i]++;
        }
    }

    // Toplogical Sort
    toplogical_sort();

    // OUTPUT
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << "\n";
    }
}