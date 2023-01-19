#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;

    int T, N;
    int fib_Arr[41] = {0, 1, };
    for(int i = 2; i < 41; i++) fib_Arr[i] = fib_Arr[i-1] + fib_Arr[i-2];

    cin >> T;
    while(T--) {
        cin >> N;
        if(N == 0) cout << "1 0\n";
        else cout << fib_Arr[N-1] << " " << fib_Arr[N] << "\n";
    }
}