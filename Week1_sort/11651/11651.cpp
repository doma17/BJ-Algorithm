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

    int n;
    cin >> n;

    pair<int, int> xy;
    vector<pair<int, int>> v(n);
    int x; int y;

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }

    sort(v.begin(), v.end(), comp);
    
    for(int i = 0; i < n; i++) cout << v[i].first << " " << v[i].second << "\n";
}