#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool comp(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second;
}

int main() {
    fastio;
    int K; int L;
    cin >> K >> L;

    // map을 통해서 해당 학번에 마지막으로 신청한 인덱스를 넣어준다.
    unordered_map<string, int> m;
    string num;
    for(int i = 0; i < L; i++) {
        cin >> num;
        m[num] = i;
    }

    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);

    for(int i = 0; i < min(K, (int)v.size()); i++) {
        cout << v[i].first << "\n";
    }
}