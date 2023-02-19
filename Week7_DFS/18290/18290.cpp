#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n, m, k;
int input[11][11];
bool visited[11][11];
int ans = -1000000;
int sum = 0;

void dfs(int cnt) {
    if(cnt == k) {
        ans = max(ans, sum);
        return;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(visited[i][j]) continue;
            // 상하좌우에 방문한 노드가 있는지 확인한다.
            if(visited[i+1][j] || visited[i-1][j] || visited[i][j-1] || visited[i][j+1]) continue;

            visited[i][j] = true;
            sum += input[i][j];
            dfs(cnt + 1);
            sum -= input[i][j];
            visited[i][j] = false;
        }
    }
}

int main() {
    fastio;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> input[i][j];
        }
    }
    dfs(0); 
    cout << ans << "\n";
}