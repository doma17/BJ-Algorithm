#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n, m; // 정점개수, 간선개수
vector<int> adj[20001];
int visited[20001];
queue<int> q;
int maxidx, maxnum, maxcnt;

// BFS 방식으로 문제해결
void bfs(int cnt) {
    visited[cnt] = true;
    q.push(cnt);

    while(!q.empty()) {
        int s = q.front(); q.pop();

        for(auto x : adj[s]) {
            if(visited[x]) continue;
            visited[x] = visited[s] + 1;
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

    int ans = 0;
    for(int i = 2; i <= n; i++) {
        if(visited[i] > maxnum) {
            maxnum = visited[i];
            maxidx = i;
            maxcnt = 1;
        }
        else if(visited[i] == maxnum) 
            maxcnt++;
    }
    cout << maxidx << " " << maxnum - 1 << " " << maxcnt << "\n";
}