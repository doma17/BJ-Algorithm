#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n, m;
int arr[9] = {0};
bool visited[9] = {0};
vector<int> input;

void dfs(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    int temp = 0; // 2. 예외적으로 "1 1 1 1"과 같은 경우가 가능한 이유는 temp를 0으로 초기화 시켜주기 때문이다.
                  // 즉 전에 사용한 temp와는 다른 변수명만 같은 temp인 것이다.
    for(int i = 0; i < n; i++) {
        if(!visited[i] && input[i] != temp) { // 1. 현재 사용해야 되는 값과 이전에 사용했던 값이 다를때만 사용한다.
            visited[i] = true;                // 같은 level의 dfs에서만 적용된다는 것이다.
            arr[cnt] = input[i];
            temp = arr[cnt];
            dfs(cnt + 1);
            visited[i] = false;
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