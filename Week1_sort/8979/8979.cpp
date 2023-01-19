#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

struct Country {
    int c_num; // 나라별 고유 번호
    int gold;
    int silver;
    int copper;
};

bool comp(Country a, Country b) {
    if(a.gold == b.gold) {
        if(a.silver == b.silver) {
            return a.copper < b.copper;
        }
        return a.silver < b.silver;
    }
    return a.gold < b.gold;
}

int main() {
    fastio;

    int N; int K;
    cin >> N >> K;
    vector<Country> v(N);

    for(int i = 0; i < N; i++) cin >> v[i].c_num >> v[i].gold >> v[i].silver >> v[i].copper;

    sort(v.begin(), v.end(), comp);

    int index;
    for(index = 0; index < N; index++) {
        if(K == v[index].c_num) break;
    }
    
    int rank = index;

    for(int i = index - 1;; i--) {
        if(v[i].gold == v[index].gold && v[i].silver == v[index].silver && v[i].copper == v[index].copper)
            rank = i + 1;
        else break;
    }
    cout << rank << "\n";
}