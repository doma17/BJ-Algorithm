#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int N; int K;
    cin >> N >> K;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    
    /*
    최대값을 찾으면 되는 것이기 때문에 K개의 제일 큰 원소들만 고름.
    왼쪽에 선택한 개수를 빼면 되기 때문에 총합에서의 뺀 값은 항상 같음.
    그러므로 그냥 K번 만큼 빼줌.
    */
    int sum = 0;
    for(int i = N-K; i < N; i++) sum += v[i];
    for(int i = 0; i < K; i++) sum -= i;
    cout << sum << "\n";
}