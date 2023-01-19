#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;

    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int N; int M;
        cin >> N >> M;
        vector<int> A(N);
        vector<int> B(M);

        for(int i = 0; i < N; i++) cin >> A[i];
        for(int i = 0; i < M; i++) cin >> B[i];

        //A가 B를 잡아먹는 것이기 때문에 A의 value보다 작은 값을 B에서 찾는것이다.
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int cnt = 0; int index = 0;
        for(int i = 0; i < N; i++) {
            while((index < M) && (A[i] > B[index])) index++;
            cnt += index;
        }
        cout << cnt << "\n";
    }
}