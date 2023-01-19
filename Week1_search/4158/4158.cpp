#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    while(1) {
        int N; int M;
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        
        vector<int> A(N);
        vector<int> B(M);
        for(int i = 0; i < N; i++) cin >> A[i];
        for(int i = 0; i < M; i++) cin >> B[i];
        // 이미 정렬된 데이터를 가져오기 때문에 정렬할 필요없다.

        int cnt = 0;
        int index_A = 0; int index_B = 0;
        while(1) {
            // 두 배열 중 하나라도 끝에 도달하면 더 이상 같은 CD가 존재할 수 없기 때문에 종료한다.
            if(index_A == N || index_B == M) break;

            if(A[index_A] < B[index_B]) index_A++;
            else if(A[index_A] > B[index_B]) index_B++;
            // 같은 수를 찾았다면 cnt를 증가시키고 두 벡터의 인덱스 모두를 증가시킨다.
            else {
                index_A++;
                index_B++;
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}