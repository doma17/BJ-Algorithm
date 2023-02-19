#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n, m;
int arr[9] = {0};
vector<int> input;

void dfs(int cnt, int index) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    int temp = 0;
    for(int i = index; i < n; i++) {
        // 15664문제에서 현재 자신의 인덱스를 중복해서 사용하는 것을 막아주는
        // "!visited[i]" 부분을 제거해 주면 된다.
        // 15665문제에서 중복을 없앤다는 조건을 추가했기 때문에 재귀함수에 현재 for문의
        // i값을 전달해줌으로서 중복을 제거한다.
        if(input[i] != temp) { 
            arr[cnt] = input[i];
            temp = arr[cnt];
            dfs(cnt + 1, i);
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
    dfs(0, 0);
}