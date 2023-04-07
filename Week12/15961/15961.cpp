#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

// 백준 15961번 문제
// 투포인터 슬라이딩

int n, d, k, c;
vector<int> arr(3000001);
map<int, int> m;
int ans;

void slide() {
    int left = 0, right = 0, cnt = 0, kind = 0;
    while(left != n - 1) { // 왼쪽 포인터가 끝에 도달할떄 종료
        if(cnt >= k) {
            // 현재 구간에 중복이 아닌 원소의 개수가 k개 이상 또는 같을 때
            if(--m[arr[left]] == 0) kind--;
            left = (left + 1) % n;
            cnt--;
        }
        else {
            // 현재 구간에 중복이 아닌 원소의 개수가 k개 미만일때
            if(m[arr[right]]++ == 0) kind++;
            right = (right + 1) % n;
            cnt++;
        }

        // 현재 계산중인 초밥의 종류가 ans보다 클때 값을 갱신한다
        if (kind >= ans) {
            ans = kind;
            if(m[c] == 0) ans++; // 기존에 계산중인 값중에 쿠폰으로 먹은게 있는지 확인
        }
    }
}

int main() {
	fastio;
    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(m.find(arr[i]) == m.end()) m.insert({arr[i], 0});
    }
		
    slide();
    cout << ans << "\n";
}