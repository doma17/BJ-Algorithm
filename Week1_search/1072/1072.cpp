#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;

    double X; double Y;
    cin >> X >> Y;

    // 100을 곱하고나서 나눠줌으로서 소숫점으로 생길 수 있는 문제를 없앤다.
    int init_rate = (Y * 100) / X ;

    // 승률이 이미 99퍼센트 이상이면 바뀔 수 없기 때문에 -1을 출력한다.
    if(init_rate >= 99) {
        cout << -1 << "\n";
        return 0;
    }

    // 이진탐색 방법을 사용한다.
    int left = 0; int right = 1000000000;
    while(left <= right) {
        int mid = (left + right) / 2;
        int cnt_rate = (Y + mid) * 100 / (X + mid);

        if(init_rate < cnt_rate) right = mid - 1;
        else left = mid + 1;
    }
    cout << left;
}