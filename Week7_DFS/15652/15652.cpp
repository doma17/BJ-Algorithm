#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n, m;
int arr[9] = {0};

void dfs(int cnt, int index) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = index; i <= n; i++) {
        arr[cnt] = i;
        dfs(cnt + 1, i);
    }
}

int main() {
    fastio;
    cin >> n >> m;
    dfs(0, 1);
}