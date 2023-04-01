
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

// 백준 2252번 문제
// 위상정렬을 통해서 풀이

int n, m;
int a, b;
vector<int> edge[32001];
int degree[32001];
vector<int> ans;

void toplogical_sort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(degree[i] != 0) continue;

        q.push(i);
    }

    // DAG 위상정렬
    while(!q.empty()) {
        int now = q.front(); q.pop();
        ans.push_back(now);

        for(auto next : edge[now]) {
            degree[next]--;

            if(degree[next] == 0) {
                q.push(next);
            }
        }
    }
}

int main() {
	fastio;
    // INPUT
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        degree[b]++;
    }

    toplogical_sort();

    // OUTPUT
    for(auto x : ans) {
        cout << x << "\n";
    }
}