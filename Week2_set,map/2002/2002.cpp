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

    vector<string> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cin >> input;
        for(int j = i + 1; j < N; j++) {
            if(m[v[i]] > m[v[j]]) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << "\n";
}