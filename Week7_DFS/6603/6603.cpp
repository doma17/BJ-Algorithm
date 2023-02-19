#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int k = -1;
int input[14];
bool visited[14];
int output[14];

void dfs(int cnt, int index) {
    // 기존 문제랑 다른 점은 복권은 6개의 숫자만 나오기 때문에
    // cnt가 6일때로 고정된다는 점이다.
    if(cnt == 6) {
        for(int i = 0; i < 6; i++)
            cout << output[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = index; i < k; i++) {
        if(!visited[i]) {
            visited[i] = true;
            output[cnt] = input[i];
            dfs(cnt + 1, i);
            visited[i] = false;
        }
    }
}

int main() {
    fastio;
    while(k != 0) {
        cin >> k;
        for(int i = 0; i < k; i++)
            cin >> input[i];
        dfs(0, 0);
        cout << "\n";
    }
}