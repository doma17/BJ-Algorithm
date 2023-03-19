#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N;
int map[100][100];
bool visited[100][100];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
queue<pair<int, int>> q;
int max_h = -1;

void bfs(int y, int x, int h) {
    visited[y][x] = true;
    q.push(make_pair(y, x));
 
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
 
            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;
            if (map[ny][nx] > h && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
}
 
int main() {
    fastio;
    // INPUT
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            max_h = max(max_h, map[i][j]);
        }
    }

    int max_area = 1;
    int cnt = 0;
    for(int h = 1; h <= max_h; h++) { // 수면 높이 설정
        // DFS
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(visited[i][j] || map[i][j] <= h)
                    continue;
                bfs(i, j, h);
                cnt++;
            }
        }

        // RESET
        max_area = max(max_area, cnt);
        memset(visited, 0, sizeof(visited));
        cnt = 0;
    }
    cout << max_area << "\n";
}
