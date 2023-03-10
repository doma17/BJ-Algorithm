#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n, m; // 정점개수, 간선개수
vector<int> adj[1001];
bool visited[1001];
int cnt;

// DFS방식으로 문제해결
void dfs(int cnt) {
    visited[cnt] = true;
    for(auto x : adj[cnt]) { // adj[cnt]에 연결된 element만 가져옴
        if(visited[x]) continue;
        dfs(x);
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
        // 무방향 그래프
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 빠짐없이 탐색하기 위해서 for문으로 탐색한다.
    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        cnt++;
        dfs(i);
    }
    cout << cnt << "\n";
}