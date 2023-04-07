#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

// 백준 1644번 문제

int main() {
	fastio;
    int n;
    cin >> n;

    // 에라토스테네스의 체
    vector<bool> v(n+1, true);
    for(int i = 2; i*i <= n; i++) {
        if(!v[i]) continue;
        for(int j = i+i; j <= n; j += i)
            v[j] = false;
    }
    // 소수만 저장
    vector<int> prime;
    for(int i = 2; i <= n; i++) {
        if(v[i]) prime.push_back(i);
    }

    // 투포인터
    int left = 0, right = 0, sum = 0, ans = 0;
    while (1) {
        if(sum >= n)
            sum -= prime[left++];
        else if(right == prime.size()) 
            break;
        else if(sum < n)
            sum += prime[right++];

        if(sum == n) ans++;
    }

    cout << ans << "\n";
}