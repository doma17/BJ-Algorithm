#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    fastio;

    int N;
    cin >> N;
    // first는 좌표, second는 색상
    vector<pair<int, int>> v(N);

    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    // 같은 색상별로 정렬한다.
    sort(v.begin(), v.end(), comp);

    int sum = 0;
    for(int i = 0; i < N; i++) {
        // i가 0또는 N-1일 경우에는 한개의 경우 밖에 존재 하지 않는다.
        if(i == 0) {
            if(v[i].second == v[i+1].second) sum += abs(v[i].first - v[i+1].first);
            else continue; // i가 0이며 색상이 한개 있는 경우
        }
        else if(i == N - 1) {
            if(v[i].second == v[i-1].second) sum += abs(v[i].first - v[i-1].first);
            else continue; // i가 N-1이며 색상이 한개 있는 경우
        }
        // 수평선 상의 다른 색이 없는 좌표 예외처리
        else if(v[i].second != v[i+1].second && v[i].second != v[i-1].second) continue;
        // 색상별로 정렬했기 때문에 색상에 달라지는 구간에서 예외처리한다.
        else if(v[i].second != v[i+1].second) sum += abs(v[i].first - v[i-1].first);
        else if(v[i].second != v[i-1].second) sum += abs(v[i].first - v[i+1].first);
        // 같은 색상에서 앞 뒤의 좌표 중 가까운 좌표를 sum에 더한다.
        else if(abs(v[i].first - v[i-1].first) < abs(v[i].first - v[i+1].first)) {
            sum += abs(v[i].first - v[i-1].first);
        }
        else {
            sum += abs(v[i].first - v[i+1].first);
        }
    }
    cout << sum << "\n";
}