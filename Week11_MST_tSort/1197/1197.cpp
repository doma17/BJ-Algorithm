#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

// 백준 1197번 문제
// 최소 신장 트리 문제 - 크루스칼 알고리즘

int v, e;
int a, b, c;
vector<pair<ll, pair<ll, ll>>> edge; // {cost, {node1, node2}}
int check[10001];
int cost;

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
    for(int i = 1; i <= v; i++)
        check[i] = i;
    
    for(auto u : edge) {
        int x = u.second.first;
        int y = u.second.second;

        if (!same(x, y)) {
            unite(x, y);
            cost += u.first;
        }
    }
}


int main() {
	fastio;
    // INPUT
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }

    sort(edge.begin(), edge.end());
    kruskal();

    // OUTPUT
    cout << cost << "\n";
}