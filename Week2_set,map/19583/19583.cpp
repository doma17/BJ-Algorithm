#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int str2time(string str) {
    return 60 * stoi(str.substr(0, 2)) + stoi(str.substr(3, 5));
}

int main() {
    fastio;

    string init;
    int S; int E; int Q;
    set<string> s;

    cin >> init;
    S = str2time(init);
    cin >> init;
    E = str2time(init);
    cin >> init;
    Q = str2time(init);

    string input; string name; int cnt = 0;
    while(cin.eof() == false) {
        cin >> input;
        int cnt_time = str2time(input);

        cin >> name;
        if(cnt_time <= S) s.insert(name);
        else if(E <= cnt_time && cnt_time <= Q) {
            if(s.find(name) != s.end()) {
                cnt++;
                auto it = s.find(name);
                s.erase(it);
            }
        }
    }
    cout << cnt;
}