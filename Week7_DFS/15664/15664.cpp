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

void dfs(int cnt, int index) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    int temp = 0;
    for(int i = index; i < n; i++) {
        // 15663번과 다른 점은 이전에 사용한 i값을 가져오기 위해서
        // dfs의 매개변수 index 파라미터를 추가한다.
        if(!visited[i] && input[i] != temp) { 
            visited[i] = true;               
            arr[cnt] = input[i];
            temp = arr[cnt];
            dfs(cnt + 1, i + 1);
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
    dfs(0, 0);
}