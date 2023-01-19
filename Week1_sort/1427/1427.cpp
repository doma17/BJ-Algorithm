#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;

    int n;
    cin >> n;

    int n_arr[10]; // n은 10자리 수까지 존재 하기 때문에 배열을 10까지 설정한다.
    int index; // index를 외부에서 int형으로 선언하여, 몇 자리까지 입력 받았는지 기록을 남긴다.

    for(index = 0; n != 0; index++) {
        n_arr[index] = n % 10; // 1의 자리수 추출
        n = n / 10; // 1의 자리수 제거
    }
    
    // sort 메소드를 사용하고, sort(첫 주소, 마지막 주소, 정렬 방법)
    // greater<?>()은 정렬을 내림차순으로 만들어준다.
    sort(n_arr, n_arr + index, greater<int>());

    for(int i = 0; i < index; i++) cout << n_arr[i];
    cout << "\n";
}