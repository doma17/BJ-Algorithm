#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;

    int N; int M;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    cin >> M;
    sort(v.begin(), v.end());

    int start = 0;
    int end = v[N-1];
    int sum; int mid; int result;
    while(start <= end) {
        sum = 0;
        mid = (start + end)/ 2;
        for(int i = 0; i < N; i++) {
            sum += min(v[i], mid);
        }

        if(M >= sum) {
            result = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    cout << result << "\n";
}