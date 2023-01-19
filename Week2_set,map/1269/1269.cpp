#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int N; int M;
    cin >> N >> M;

    set<int> A;
    int num;
    for(int i = 0; i < N; i++) {
        cin >> num;
        A.insert(num);
    }

    set<int> B;
    for(int i = 0; i < M; i++) {
        cin >> num;
        B.insert(num);
    }
    
    int overlap_cnt = 0;
    // 원소의 개수가 적은 집합에서 원소를 꺼냄으로서 연산실행 횟수를 줄인다.
    if(N < M) { 
        for(auto x : A) {
            auto it = B.find(x);
            if(it != B.end()) overlap_cnt++;
        }
    }
    else {
        for(auto x : B) {
            auto it = A.find(x);
            if(it != A.end()) overlap_cnt++;
        }
    }

    // 두 집합의 교집합 원소를 제외한 원소들을 출력
    cout << N + M - overlap_cnt * 2 << "\n";
}