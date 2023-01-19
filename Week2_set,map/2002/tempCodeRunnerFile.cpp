#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;

    int N;
    cin >> N;

    map<string, int> m;
    string input;
    for(int i = 0; i < N; i++) {
        cin >> input;
        m[input] = i;
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cin >> input;
        if(m[input] < i) cnt++;
    }

    cout << cnt << "\n";
}