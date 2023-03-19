#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N, M, K;
bool visited[100][100];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int cnt = 0;

void dfs(int x, int y) { // DFS 풀이 방법
    visited[y][x] = true;
    cnt++;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M) // 범위를 벗어나지 않도록 제한
            continue;
        if(visited[ny][nx]) // 이미 방문한 곳인지 확인
            continue;
        dfs(nx, ny);
    }
}
 
int main() {
    fastio;
    // INPUT
    cin >> M >> N >> K;
    int x, y, a, b;
    for(int i = 0; i < K; i++) {
        cin >> x >> y >> a >> b;

        for(int j = x; j < a; j++) {
            for(int k = y; k < b; k++) {
                visited[k][j] = true;
            }
        }
    }

    // DFS
    vector<int> v;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j]) continue;
            cnt = 0;
            dfs(j, i); // dfs 풀이방법 사용
            v.push_back(cnt);
        }
    }
    
    // OUTPUT
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(auto x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
