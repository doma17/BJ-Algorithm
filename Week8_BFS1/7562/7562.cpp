#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int T, N;
int map[300][300];
bool visited[300][300];
int start_x, start_y;
int end_x, end_y;

queue<pair<int, int>> q;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

void bfs() {
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) // 범위를 벗어나지 않도록 제한
                continue;
            if(map[ny][nx] == 0 && visited[ny][nx] == 0) {
                map[ny][nx] = map[y][x] + 1; // 몇번 이동했는지 입력해 놓는다.
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

void reset() {
    while(!q.empty()) q.pop();
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
}
 
int main() {
    fastio;
    cin >> T;
    while(T--) {
        // INPUT
        cin >> N;
        cin >> start_x >> start_y;
        cin >> end_x >> end_y;

        map[start_y][start_x] = 1;
        visited[start_y][start_x] = true;
        q.push({start_y, start_x});

        // BFS
        bfs();

        // RESULT
        cout << map[end_y][end_x] - 1 << "\n";
        // RESET
        reset();
    }    
}
