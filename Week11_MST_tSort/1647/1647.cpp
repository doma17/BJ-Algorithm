#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

// 백준 1647번 문제
// 최소 신장 트리 문제 - 크루스칼 알고리즘

// 최소 스패닝 트리를 만들고 나서 그 값중 가장 큰 cost를 가진
// 간선을 빼주면, 유지비의 합을 최소로 하여 마을을 분리할 수 있다.

int n, m;
int a, b, c;
vector<pair<ll, pair<ll, ll>>> edge; // {ans, {node1, node2}}
int check[100001];
int ans;
int maxCost;

int find(int x) {
    if(check[x] == x) return x;
    return check[x] = find(check[x]);
}

// 같은 컴포넌트가 있는지 확인하는 함수
bool same(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return true;
    return false;
}

// 두 컴포넌트를 합치는 함수
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    check[y] = x;
}

// 크루스칼 알고리즘
void kruskal() {

    for(int i = 1; i <= n; i++)
        check[i] = i;
    
    for(auto u : edge) {
        int cost = u.first;
        int x = u.second.first;
        int y = u.second.second;

        if (!same(x, y)) {
            maxCost = max(maxCost, cost);
            ans += cost;
            unite(x, y);
        }
    }
}


int main() {
	fastio;
    // INPUT
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }

    sort(edge.begin(), edge.end());
    kruskal();

    // OUTPUT
    cout << ans - maxCost << "\n";
}