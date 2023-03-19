#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N, K;
bool visited[100001];
queue<pair<int, int>> q;

void isPush(int x, int cnt) {
    if(0 <= x && x < 100001) {
        if(visited[x]) return;
        visited[x] = true;
        q.push({x, cnt + 1});
    }
}

void bfs(int a) {
    q.push({a, 0});
    
    while(!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(x == K) {
            cout << cnt << "\n";
            return;
        }
        isPush(x + 1, cnt);
        isPush(x - 1, cnt);
        isPush(2 * x, cnt);
    }
}
 
int main() {
    fastio;
    cin >> N >> K;
    visited[N] = true;
    bfs(N);
}
