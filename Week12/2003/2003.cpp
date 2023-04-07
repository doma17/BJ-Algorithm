#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

// 백준 2003번 문제
// 투포인터

int n, m;
vector<int> arr(10001);
int ans;
int sum, start;

int main() {
	fastio;
	// 핵심은 input data를 받는 것과 투 포인터 연산을 동시에 한다는 점이다.
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		
		sum += arr[i];
		while(sum > m) {
			sum -= arr[start++];
		}
			
		if(sum == m) ans++;
	}

	cout << ans << "\n";
}