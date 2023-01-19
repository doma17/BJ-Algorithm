#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;

    int n; int m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);

    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < m; i++) cin >> B[i];

    // 벡터 A, B를 병합 시킨 새로운 백터를 생성한다.
    vector<int> AB;
    AB.insert(AB.end(), A.begin(), A.end());
    AB.insert(AB.end(), B.begin(), B.end());

    sort(AB.begin(), AB.end());

    for(int i = 0; i < n + m; i++) cout << AB[i] << " ";
    cout << "\n";
}