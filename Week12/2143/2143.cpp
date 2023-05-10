#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

// 백준 1644번 문제
// subset_sum

int main() {
	fastio;
    int T, n, m;
    vector<int> A(n + 1);
    vector<int> B(m + 1);
    unordered_map<int, int> A_cnt = {{0, 1}};
    unordered_map<int, int> B_cnt = {{0, 1}};

    cin >> T >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> B[i];

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += A[j];
            A_cnt[sum]++;
        }
    }

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += A[j];
            B_cnt[sum]++;
        }
    }

    ll ans = 0;
    for(auto x : A_cnt) {
        int diff = T - x.first;

        if(B_cnt.find(diff) != B_cnt.end()) {
            ans = x.second * B_cnt[diff];
        }
    }
    cout << ans << "\n";
}