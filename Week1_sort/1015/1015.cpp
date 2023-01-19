#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;

    // 비내림차순에 대해서 이해 못해서 못품 인터넷 참고함
    // https://suri78.tistory.com/271
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        v.push_back(make_pair(value, i));
    }
    sort(v.begin(), v.end());
    vector<int> p(N);
    for(int i = 0; i < N; i++) p[v[i].second] = i;
    for(int i = 0; i < N; i++) cout << p[i] << " ";
    cout << "\n";
}