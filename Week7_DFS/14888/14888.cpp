#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n;
int input[12];
int operators[5];
int ans_max = -2147483648;
int ans_min = 2147483647;

void dfs(int sum, int index) {
    if(index == n) {
        ans_max = max(ans_max, sum);
        ans_min = min(ans_min, sum);
        return;
    }
    for(int i = 1; i <= 4; i++) {
        if(operators[i] > 0) {
            operators[i]--;
            if(i == 1) dfs(sum + input[index], index + 1);
            else if(i == 2) dfs(sum - input[index], index + 1);
            else if(i == 3) dfs(sum * input[index], index + 1);
            else if(i == 4) dfs(sum / input[index], index + 1);
            operators[i]++;
        }
    }
    return;
}

int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> input[i];
    for(int i = 1; i <= 4; i++)
        cin >> operators[i];
    dfs(1, 1);
    cout << ans_max << "\n" << ans_min << "\n";
}