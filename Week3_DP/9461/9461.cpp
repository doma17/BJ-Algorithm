#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;

    int T, N;
    ll pado_Arr[101] = {1, 1, 1, 2, 2, };
    // 파도반 수열은 직전의 삼각형과 index가 -5 작은 삼각형의 영향을 받는다.
    for(int i = 5; i < 101; i++) pado_Arr[i] = pado_Arr[i-1] + pado_Arr[i-5];

    cin >> T;
    while(T--) {
        cin >> N;
        cout << pado_Arr[N-1] << "\n"; 
    }
}