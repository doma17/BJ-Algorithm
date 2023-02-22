#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n, m, v;
vector<int> adj[1001];
bool visited[1001];
queue<int> q;

void dfs(int cnt) {
    visited[cnt] = true;
    cout << cnt << " ";

    // 조건1. 정점 번호가 작은 것부터 방문해야 된다.
    sort(adj[cnt].begin(), adj[cnt].end());
    for(auto u : adj[cnt]) {
        if(visited[u]) continue;
        dfs(u);
    }
}

void bfs(int cnt) {
    visited[cnt] = true;
    q.push(cnt);

    while(!q.empty()) {
        int s = q.front(); q.pop();
        cout << s << " ";

        for(auto u : adj[s]) {
            if(visited[u]) continue;
            q.push(u);
            visited[u] = true;
        }
    }
}

int main() {
    fastio;
    cin >> n >> m >> v;
    // auto문을 사용하기 위해서 memset함수로 adj, visited의 길이를 재정의한다.
    memset(adj, 0, n);
    memset(visited, 0, n);

    int node_a, node_b; // noda_a와 noda_b가 연결되있는 path를 뜻한다.
    for(int i = 1; i <= m; i++) {
        cin >> node_a >> node_b;
        adj[node_a].push_back(node_b);
        adj[node_b].push_back(node_a);
    }
    
    dfs(v);
    cout << "\n";

    memset(visited, 0, n); // bfs연산을 위해 visited 배열을 초기화한다.
    bfs(v);
    cout << "\n";
}