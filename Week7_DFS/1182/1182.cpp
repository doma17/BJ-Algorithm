#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n, s;
bool visited[21] = {0};
vector<int> input;
int sum = 0;
int result = 0;

void dfs(int cnt, int index) {
    // 기본 N,M 문제와는 다르게 수열의 합이 S가 되어야 하는 문제이다.
    // 아래의 for문에서 해당 dfs에서의 sum을 구해서 sum == s를 만족하면
    // 카운트를 하나 증가해준다.
    if(sum == s && cnt != 0) result++;

    for(int i = index; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            sum += input[i];

            dfs(cnt + 1, i);

            visited[i] = false;
            // 다른 노드로 넘어가야 되기 때문에 이전에 사용한 값을 빼서 부모 노드의 상태로 되돌려 놓는다.
            sum -= input[i];            
        }
    }
}

int main() {
    fastio;
    cin >> n >> s;
    input.resize(n);
    for(int i = 0; i < n; i++)
        cin >> input[i];
    sort(input.begin(), input.end());

    dfs(0, 0);
    cout << result << "\n";
}