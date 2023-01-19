#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

map<int, int> order_map;
bool comp(pair<int, int>& a, pair<int, int>& b) {
    if(a.second == b.second) return order_map[a.first] < order_map[b.first];
    return a.second > b.second;
}

int main() {
    fastio;
    int N; int C;
    cin >> N >> C;

    map<int, int> cnt_map;
    // map<int, int> order_map;

    int num;
    for(int i = 0; i < N; i++) {
        cin >> num;
        cnt_map[num]++;
        if(order_map[num] == 0) order_map[num]= i + 1;
    }

    vector<pair<int, int>> v(cnt_map.begin(), cnt_map.end());
    sort(v.begin(), v.end(), comp);
    for(auto x : v) {
        for(int i = 0; i < x.second; i++) cout << x.first << " ";
    }
    cout << "\n";
}