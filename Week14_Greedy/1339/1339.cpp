#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
#define INF 987654321

// 백준 1339번 문제
// https://www.acmicpc.net/problem/1339

// DEFINITION
int N;
int digit[26];

bool cmp(int &a, int &b) {
    return a > b;
}

int main() {
	fastio;
    // INPUT
    cin >> N;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        int pow = 1;
        for(int j = str.length() - 1; j >= 0; j--) {
            digit[str[j] - 'A'] += pow;
            pow *= 10;
        }
    }

    // PROCESS
    sort(digit, digit + 26, cmp);

    // 정렬을 통해서 자리수의 총합이 가장 큰 알파벳부터 큰 숫자를 부여한다.
    int num = 9;
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        if(digit[i] == 0) break;
        ans += digit[i] * num--;
    }
    cout << ans << "\n";

    return 0;
}