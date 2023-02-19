#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n, m;
int arr[9] = {0};
vector<int> input;

void dfs(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    int temp = 0;
    for(int i = 0; i < n; i++) {
        // 15664문제에서 현재 자신의 인덱스를 중복해서 사용하는 것을 막아주는
        // "!visited[i]" 부분을 제거해 주면 된다.
        if(input[i] != temp) { 
            arr[cnt] = input[i];
            temp = arr[cnt];
            dfs(cnt + 1);
        }
    }
}

int main() {
    fastio;
    cin >> n >> m;
    input.resize(n);
    for(int i = 0; i < n; i++)
        cin >> input[i];
    sort(input.begin(), input.end());
    dfs(0);
}