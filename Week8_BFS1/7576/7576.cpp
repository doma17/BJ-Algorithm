#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N, M;
int map[1000][1000];
bool visited[1000][1000];

queue<pair<int, int>> q;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int ans;

void bfs() {
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= M || ny < 0 || ny >= N) // 범위를 벗어나지 않도록 제한
                continue;
            if(map[ny][nx] == 0 && visited[ny][nx] == 0) {
                map[ny][nx] = map[y][x] + 1; // 몇일이 걸렸는지 확인하는 방법
                q.push({ny, nx});
            }
        }
    }
}
 
int main() {
    fastio;
    // INPUT
    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];

            if(map[i][j] == 1) q.push({i, j});
        }
    }

    bfs();

    // 익지 않은 토마토가 없는지 검사
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == 0) {
                cout << "-1\n";
                return 0;
            }
            if(ans < map[i][j]) {
                ans = map[i][j];
            }
        }
    }
    cout << ans - 1 << "\n";
}
