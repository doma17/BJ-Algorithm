#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 2100000000 // 21억
typedef long long int ll;

// 백준 1865번 문제
// 음수 가중치가 존재하기 때문에 다익스트라가 아닌 벨만-포드 알고리즘을 사용한다.

int TC, N, M, W;
int S, E, T;
vector<pair<int, int> > edge[501];
ll dist[501];
bool check;

void bellman_ford(int x) {
	dist[x] = 0;
	for(int j = 1; j <= N; j++) {
		for(int i = 1; i <= N; i++) {
			for(auto e : edge[i]) {
				int cnt = i;
				int next = e.first;
				int cost = e.second;

				if(dist[next] <= dist[cnt] + cost) continue;
				dist[next] = dist[cnt] + cost;

				if(j != N) continue;
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

void reset() {
	for(int i = 0; i <= N; i++) 
		dist[i] = INF;
	for(int i = 1; i <= N; i++)
		edge[i].clear();
	check = false;
}

int main() {
	fastio;
	cin >> TC;
	while(TC--) {
		reset();
		
		cin >> N >> M >> W;
		for(int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			edge[S].push_back({E, T}); 
			edge[E].push_back({S, T});
		}
		for(int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			edge[S].push_back({E, -T});
		}

		bellman_ford(1);
	}
}