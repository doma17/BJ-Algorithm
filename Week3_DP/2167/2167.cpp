#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;

    int N, M;
    cin >> N >> M;

    int Arr[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> Arr[i][j];
        }
    }

    int K, x1, y1, x2, y2;
    cin >> K;
    while(K--) {
        cin >> x1 >> y1 >> x2 >> y2;
        
        int sum = 0;
        for(int i = x1; i <= x2; i++) {
            for(int j = y1; j <= y2; j++) {
                sum += Arr[i-1][j-1];
            }
        }
        cout << sum << "\n";
    }
}