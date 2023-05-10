#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

int N, M;
map<string, int> m;
vector<string> v;

int main() {
	fastio;
    cin >> N >> M;
    for(int i = 0; i < N + M; i++) {
        string str;
        cin >> str;
        m[str]++;
        if(m[str] >= 2)
            v.push_back(str);
    }

    sort(v.begin(), v.end());

    cout << v.size() << "\n";
    for(auto x : v)
        cout << x << "\n";
}