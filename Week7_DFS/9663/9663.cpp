#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

int n;
bool isused1[40];
bool isused2[40];
bool isused3[40];
int cnt = 0;

void dfs(int index) {
    if(index == n) {
        cnt++;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(isused1[i] || isused2[i + index] || isused3[index-i + n-1])
            continue;
        isused1[i] = 1;
        isused2[i + index] = 1;
        isused3[index-i + n-1] = 1;
        dfs(index + 1);
        isused1[i] = 0;
        isused2[i + index] = 0;
        isused3[index-i + n-1] = 0;
    }
}

int main() {
    fastio;
    cin >> n;
    dfs(0);
    cout << cnt << "\n";
}