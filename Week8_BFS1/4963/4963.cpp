#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int w, h;
int map[50][50];
bool visited[50][50];
int dx[] = {1, 0, 0, -1, 1, 1, -1, -1};
int dy[] = {0, 1, -1, 0, 1, -1, -1, 1};
int cnt = 0;

void dfs(int x, int y) { // DFS 풀이 방법
    visited[y][x] = true;

    for(int i = 0; i < 8; i++) { // 대각선으로 이동가능하기 때문에 8가지의 경우가 존재한다.
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= w || ny < 0 || ny >= h) // 범위를 벗어나지 않도록 제한
            continue;
        if(visited[ny][nx] || map[ny][nx] == 0) // 이미 방문한 곳인지 확인
            continue;
        dfs(nx, ny);
    }
}
 
int main() {
    fastio;
    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        // INPUT
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++)  {
                cin >> map[i][j];
            }
        }

        // DFS
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(visited[i][j] || map[i][j] == 0) continue;
                cnt++;
                dfs(j, i); // dfs 풀이방법 사용
            }
        }

        // OUTPUT
        cout << cnt << "\n";
        
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        cnt = 0;
    }
}
