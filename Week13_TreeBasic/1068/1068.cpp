#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;
#define MAX 100001

int N, K;
bool visited[MAX];
vector<int> v[MAX];
int root, ans;

int dfs(int x) {
	if(x == K) return -1;
	if(v[x].size() == 0) {
		ans++;
		return 0;
	}
    for(int i = 0; i < v[x].size(); i++) {
        int next = dfs(v[x][i]);
		if(next == -1 && v[x].size() == 1) {
			ans++;
		}
    }
	return 0;
}

int main() {
	fastio;
    cin >> N;
    for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if(x == -1)
			root = i;
		else
			v[x].push_back(i);
    }
	cin >> K;

    dfs(root);

	cout << ans << "\n";
}