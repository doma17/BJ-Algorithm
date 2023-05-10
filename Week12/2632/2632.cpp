#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

// 백준 2632번 문제
// subset_sum

int size, n, m;
vector<int> A(1001);
vector<int> B(1001);
map<int, int> map_A;
map<int, int> map_B;
int ans;

void slide() {

}

int main() {
	fastio;
    cin >> size;
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        cin >> A[i];
        if(map_A.find(A[i]) == map_A.end()) map_A.insert({A[i], 0});
    }

    for(int i = 0; i < n; i++) {
        cin >> B[i];
        if(map_B.find(B[i]) == map_B.end()) map_B.insert({B[i], 0});
    }
		
    slide();
    cout << ans << "\n";
}