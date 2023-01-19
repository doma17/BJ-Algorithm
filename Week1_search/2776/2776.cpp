#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int T; int N; int M;

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N;
        vector<int> note_1(N);
        for(int i = 0; i < N; i++) cin >> note_1[i];
        sort(note_1.begin(), note_1.end());

        cin >> M;
        vector<int> note_2(M);
        for(int i = 0; i < M; i++) cin >> note_2[i];

        // 이진탐색 방법을 사용한다. 
        for(int i = 0; i < M; i++) {
            int left = 0; int right = N-1; int mid;
            bool checked = true;

            while(left <= right) {
                mid = (left + right) / 2;
                if(note_2[i] < note_1[mid]) right = mid - 1;
                else if(note_2[i] > note_1[mid]) left = mid + 1;
                else {
                    // 탐색에 성공하면 1을 출력
                    checked = false;
                    cout << "1\n";
                    break;
                }
            }
            // 탐색에 실패했으면 0을 출력
            if(checked) cout << "0\n";
        }
    }
}