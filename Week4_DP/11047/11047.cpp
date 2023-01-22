#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    ll N, K, sum = 0;
    cin >> N >> K;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    reverse(v.begin(), v.end());

    int cnt = 0;
    for(auto x : v) {
        if(K >= x) {
            cnt += K / x;
            K %= x;
            if(K <= 0) break;
        }
    }
    cout << cnt << "\n";
}