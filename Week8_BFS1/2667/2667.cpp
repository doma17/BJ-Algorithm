#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N;
int map[300][300];
bool visited[300][300];

queue<pair<int, int>> q;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int complex_cnt = 0;
int house_cnt = 0;

void bfs(int i, int j) {
    q.push({i, j});
    visited[i][j] = true;
    house_cnt++;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) // 범위를 벗어나지 않도록 제한
                continue;
            if(visited[ny][nx]) // 이미 방문한 곳인지 확인
                continue;
            if(map[ny][nx] == 1) { // 현재 위치에 집이 존재하는지 확인
                visited[ny][nx] = true;
                q.push({ny, nx});
                house_cnt++;
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
    // INPUT
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    // BFS
    queue<int> q_cnt;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j]) continue;
            if(map[i][j] == 0) continue;



            bfs(i, j);
            q_cnt.push(house_cnt);
            house_cnt = 0;
            complex_cnt++;
        }
    }
    
    // OUTPUT
    cout << complex_cnt << "\n";
    sort(q_cnt);
    while(!q_cnt.empty()) {
        cout << q_cnt.front() << "\n";
        q_cnt.pop();
    }
}
