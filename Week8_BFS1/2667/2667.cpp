#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N;
int map[26][26];
bool visited[26][26];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int cnt = 0;

void dfs(int x, int y) { // DFS 풀이 방법
    visited[y][x] = true;
    cnt++;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N) // 범위를 벗어나지 않도록 제한
            continue;
        if(visited[ny][nx]) // 이미 방문한 곳인지 확인
            continue;
        if(map[ny][nx] == 0) // 현재 위치에 집이 존재하는지 확인
            continue;
        dfs(nx, ny);
    }
}
 
int main() {
    fastio;
    // INPUT
    cin >> N;
    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;

        for(int j = 0; j < N; j++) {
            map[i][j] = input.at(j) - '0';
        }
    }

    // DFS
    vector<int> v;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j]) continue;
            if(map[i][j] == 0) continue;

            dfs(j, i); // dfs 풀이방법 사용
            v.push_back(cnt);
            cnt = 0;
        }
    }
    
    // OUTPUT
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(auto x : v) {
        cout << x << "\n";
    }
}
