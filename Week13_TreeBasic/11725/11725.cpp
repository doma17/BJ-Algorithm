#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;
#define MAX 100001

int N;
int ans[MAX];
bool visited[MAX];
vector<int> v[MAX];

void dfs(int x) {
    visited[x]=true;
    for(int i = 0; i < v[x].size(); i++) {
        int next = v[x][i];
        if(!visited[next]) {
            ans[next] = x;
            dfs(next);
        }
    }
}

int main() {
    fastio;
    cin >> N;

    for(int i = 0; i < N-1; i++) {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    for(int i = 2; i <= N; i++)
        cout << ans[i] << "\n";
}