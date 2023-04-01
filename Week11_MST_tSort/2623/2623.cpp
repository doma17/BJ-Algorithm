
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

// 백준 2623번 문제
// 위상정렬을 통해서 풀이

int n, m;
vector<int> edge[1001];
int degree[1001];
int cost[1001];
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
    int num , a = 0, b = 0;
    // INPUT
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> num;
        for(int j = 0; j < num; j++) {
            cin >> b;

            if(j != 0) {
                edge[a].push_back(b);
                degree[b]++;
            }
            a = b;
        }
    }

    toplogical_sort();

    // OUTPUT
    if(ans.size() != n) {
        cout << 0 << "\n";
        return 0;
    }
    for(auto x : ans) {
        cout << x << "\n";
    }
}