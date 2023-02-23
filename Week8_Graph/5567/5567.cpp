#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n, m; // 정점개수, 간선개수
vector<int> adj[101];
bool visited[101];
queue<int> q;
int ans = 0;

// BFS 방식으로 문제해결
void bfs(int cnt) {
    visited[cnt] = true;
    q.push(cnt);

    while(!q.empty()) {
        int s = q.front(); q.pop();
        ans++;
        
        for(auto x : adj[s]) {
            if(visited[x]) continue;
            visited[x] = true;
            q.push(x);
        }
    }
}

int main() {
    fastio;
    cin >> n >> m;
    // 배열 길이 재정의
    memset(adj, 0, n);
    memset(visited, 0, n);

    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    cout << ans - 1 << "\n";
}