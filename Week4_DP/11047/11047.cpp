#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    ll N, K, sum = 0;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    int cnt = 0;
    for(int i = N-1; i >= 0; i--) {
        if((K - sum) / v[i] > 0 && (K - sum) >= v[i]) {
            sum += v[i] * (K - sum) / v[i];
            cnt += (K - sum) / v[i];
        }
    }

    cout << cnt << "\n";
}