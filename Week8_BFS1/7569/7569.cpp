#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N, M ,H;
int map[100][100][100];

queue<tuple<int, int, int>> q;
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
int ans;

void bfs() {
    while(!q.empty()) {
        int z = get<0>(q.front());
        int y = get<1>(q.front());
        int x = get<2>(q.front());
        q.pop();

        for(int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) // 범위를 벗어나지 않도록 제한
                continue;
            if(map[nz][ny][nx] == 0) {
                map[nz][ny][nx] = map[z][y][x] + 1; // 몇일이 걸렸는지 확인하는 방법
                q.push({nz, ny, nx});
            }
        }
    }
}
 
int main() {
    fastio;
    // INPUT
    cin >> M >> N >> H;
    for(int k = 0; k < H; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> map[k][i][j];
                // 기존에 익어있는 포도를 큐에 먼저 삽입 함으로써 탐색 시간을 단축
                if(map[k][i][j] == 1) q.push({k, i, j}); 
            }
        }
    }
    

    bfs();

    // 익지 않은 토마토가 없는지 검사
    for(int k = 0; k < H; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(map[k][i][j] == 0) {
                    cout << "-1\n";
                    return 0;
                }
                if(ans < map[k][i][j]) {
                    ans = map[k][i][j];
                }
            }
        }
    }
    cout << ans - 1 << "\n";
}
