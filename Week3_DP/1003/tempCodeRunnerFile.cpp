#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int cnt_zero, cnt_one;
int fibonacci(int n) {
    if(n == 0) {
        cnt_zero++;
        return 0;
    }
    else if(n == 1) {
        cnt_one++;
        return 1;
    }
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    fastio;
    int T, N;
    cin >> T;
    while(T--) {
        cin >> N;
        cnt_zero = 0;
        cnt_one = 0;
        fibonacci(N);
        cout << cnt_zero << " " << cnt_one << "\n";
    }
}