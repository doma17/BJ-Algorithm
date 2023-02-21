#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n;

void dfs(int index, string str) {
    int size = str.size();
    for(int i = 1; i <= size / 2; i++) { // 좋은 수열 검사
        // 반복되는 똑같은 수열이 있는지 검사한다.
        if(str.substr(size - i, i) == str.substr(size - 2 * i, i)) {
            cout << "BAD: " << str << "\n";
            return;
        }
    }
    if(index == n) {
        cout << str << "\n";
        exit(0); // 위의 수열 검사를 통과한 제일 첫 수가 가장 작은 수이기 때문에 종료한다.
    }
    //DFS
    dfs(index + 1, str + "1");
    dfs(index + 1, str + "2");
    dfs(index + 1, str + "3");
}

int main() {
    fastio;
    cin >> n;
    dfs(0, "");
}