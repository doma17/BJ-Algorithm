#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int T, M, N, K;
int x, y;
int map[51][51];
bool visited[51][51];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int cnt;

void dfs(int y, int x) {
    visited[y][x] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= M || ny < 0 || ny >= N) 
            continue;
        if(map[ny][nx] == 1 && visited[ny][nx] == 0)
            dfs(ny, nx);
    }
}
 
int main() {
    fastio;
    cin >> T;
    while(T--) {
        // INPUT
        cin >> M >> N >> K;
        for(int i = 0; i < K; i++) {
            cin >> x >> y;
            map[y][x] = 1;
        }

        // BFS 계산
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(visited[i][j] || map[i][j] == 0) continue;
                dfs(i, j);
                cnt++;
            }
        }

        // OUTPUT
        cout << cnt << "\n";

        // 초기화
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        cnt = 0;
    }
}
