#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
#define INF 987654321
#define MAX 1001

// 백준 11399번 문제
// https://www.acmicpc.net/problem/11399

int main() {
	fastio;
    int N;
    vector<int> v;

    cin >> N;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    ll sum = 0, ans = 0;
    for(int i = 0; i < v.size(); i++) {
        sum += v[i];
        ans += sum;
    }
    cout << ans << "\n";
}