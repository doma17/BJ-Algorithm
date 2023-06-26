#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
#define INF 987654321
#define MAX 300001

// 백준 1513번 문제
// https://www.acmicpc.net/problem/1513

// DEFINITION
int N, M, C;
int city[51][51];
int ans[51];

void bfs(int x, int y, int cnt, int top) {
    if(city[x][y] != 0) {
        if(city[x][y] > top) {
            cnt++;
            top = city[x][y];
        }
        else return;
    }

    if(x == N && y == M) {
        ans[cnt]++;
        return;
    }

    bfs(x + 1, y, cnt, top);
    bfs(x, y + 1, cnt, top);
}

int main() {
	fastio;
    // INPUT
    cin >> N >> M >> C;
    for(int i = 1; i <= C; i++) {
        int x, y;
        cin >> x >> y;
        city[x][y] = i;
    }

    bfs(1, 1, 0, 0);

    for(int i = 1; i <= C; i++)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}