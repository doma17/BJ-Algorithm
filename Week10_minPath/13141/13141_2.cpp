#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321

// 백준 13141번 문제

int n, m;
int s, e, l;
int edge[201][201] = {-1};
int dist[201][201] = {INF};

void floyd_warshall() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

double time_calc(int node1, int node2, int vertex) {
    double length = vertex;
    for(int time = 0; time < abs(node1 - node2);) {
        length--;
        time++;
        if(time >= vertex) return time;
    }
    return (max(node1, node2) + (length / 2));
}

void ignition() {
    double time = INF;
    
    for(int k = 1; k <= n; k++) {
        double max_time = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) {
                
            }
        }
    }
}

int main() {
	fastio;
    // INPUT
    cin >> n >> m;

    memset(edge, -1, sizeof(edge));
    memset(dist, INF, sizeof(dist));
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for(int i = 0; i < m; i++) {
        cin >> s >> e >> l;
        if(edge[s][e] == -1 || edge[s][e] < l) {
            edge[s][e] = l;
            edge[e][s] = l;
        }
        if(dist[s][e] == INF || l < dist[s][e]) {
            dist[s][e] = l;
            dist[e][s] = l;
        }
    }

    floyd_warshall();
    cout << ignition() << "\n";
}