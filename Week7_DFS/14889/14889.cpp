#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n;
bool visited[21];
int input[21][21] = {0};
int ans = 1215752191;

void dfs(int cnt, int index) {
    if(cnt == n / 2) { // n의 절반까지만 가면 모든 경우가 정해진 것이기 때문에 연산을 한다.
        int start = 0, link = 0;
        
        // i, j인덱스 모두 true, false 인 곳은 각각 n/2개가 존재한다.
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(visited[i] && visited[j]) start += input[i][j];
                if(!(visited[i] || visited[j])) link += input[i][j];
            }
        }

        int tmp = abs(start - link);
        ans = min(ans, tmp);
        return;
    }
    for(int i = index; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true; // 현재 내가 방문중인 인덱스를 start팀에 귀속되었다고 가정한다.
            dfs(cnt + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> input[i][j];
        }
    }
    dfs(0, 1);
    cout << ans << "\n";
}