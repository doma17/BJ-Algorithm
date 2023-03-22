#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long ll;

// 백준 11637문제
// 이 문제는 음수 가중치를 두고 있기 때문에
// 다익스트라 알고리즘이 아닌 벨만 포드 알고리즘을 사용한다.

int N, M;
int A, B, C;
vector<pair<int, int>> v[501];
ll dist[501]; // 비용총합
bool check; // 음수 가중치 사이클 존재여부 확인 변수

void bellman_ford() {
    // 1. dist 배열의 사이즈를 dist 변열의 길이 만큼 재정의하며, 모두 INF 값으로 채운다.
    // 2. 초기값 설정 - 시작 노드에서 시작 노드로 도착할때 드는 비용은 0이다.
    for(int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;

    // 출발 노드에서 도착 노드가 N-1번 연결되어 있을 수 있기 때문에 N번 반복한다.
    for(int i = 1; i <= N; i++) {
        // Bellma_Ford Algorithm 
        for(int j = 1; j <= N; j++) {
            for(auto x : v[j]) {
                // 인덱스를 now, next 변수에 저장하고, 해당하는 소요시간 time 변수로 설정
                int now = j;
                int next = x.first;
                int time = x.second;
                
                // 아직 도달하지 않은 노드는 설정하지 않는다.
                // 다음에 도착하는 노드의 시간의 최솟값을 저장 or 유지
                if (dist[now] == INF) continue;
                // dist[next] = min(dist[next], dist[now] + time)
                if (dist[next] <= dist[now] + time) continue;
				dist[next] = dist[now] + time;
				if (i == N) check = true;
            }
        }
    }
    
    if(check) cout << "-1\n";
    else {
        for(int i = 2; i <= N; i++) {
            if(dist[i] == INF) cout << "-1\n";
            else cout << dist[i] << "\n";
        }
    }
}

int main() {
    fastio;
    // INPUT
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        v[A].push_back({B, C});
    }
    bellman_ford();
}
