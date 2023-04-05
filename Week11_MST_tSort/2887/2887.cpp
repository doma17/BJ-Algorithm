#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

// 백준 2887번 문제
// 최소 신장 트리 문제 - 유니온 파인드 알고리즘

int n;
int x, y, z;
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;

vector<tuple<int, int, int>> edge; // {cost, node1, node2}
int parent[100001];
ll ans;

// 최종적으로 재귀를 통해서 연결 되어있는 모든 노드들의 부모 노드를 찾는 함수
int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// 같은 컴포넌트가 있는지 확인하는 함수
bool same(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return false;
    parent[x] = y;
    return true;
}

void union_find() {
    // 기본적으로 초기값은 자신의 부모노드를 자기 자신 노드로 설정한다.
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // union_find 기법을 통해서 연결한다.
    int a, b, cost;
    for(auto e : edge) {
        tie(cost, a, b) = e;
        
        if(same(a, b))
            ans += cost;
    }
}

int main() {
	fastio;
    
    // INPUT
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        X.push_back({x, i});
        Y.push_back({y, i});
        Z.push_back({z, i});
    }

    // 정렬을 통해서 가장 가까운 거리 값을 index + 1, index - 1 로 정리한다.
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    // edge -> {cost, node1, node2}
    for(int i = 0; i < n-1; i++) {
        edge.push_back({abs(X[i].first - X[i + 1].first), X[i].second, X[i + 1].second});
        edge.push_back({abs(Y[i].first - Y[i + 1].first), Y[i].second, Y[i + 1].second});
        edge.push_back({abs(Z[i].first - Z[i + 1].first), Z[i].second, Z[i + 1].second});
    }

    sort(edge.begin(), edge.end());
    union_find();

    // OUTPUT
    cout << ans << "\n";
}