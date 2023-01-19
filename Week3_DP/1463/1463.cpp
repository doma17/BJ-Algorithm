#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    int N;
    cin >> N;
    int Arr[1000000];

    for(int i = 2; i <= N; i++) {
        Arr[i] = Arr[i-1] + 1;
        if(i % 3 == 0)
            Arr[i] = min(Arr[i/3] + 1, Arr[i]);
        if(i % 2 == 0)
            Arr[i] = min(Arr[i/2] + 1, Arr[i]);
    }
    cout << Arr[N] << "\n";
}