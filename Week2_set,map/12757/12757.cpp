#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int N, M, K;
    cin >> N >> M >> K;
    map<int, int> m;
    
    int key, value;
    while(N--) {
        cin >> key >> value;
        m[key] = value;
    }

    int num;
    while(M--) {
        cin >> num >> key;
        auto it_back = m.lower_bound(key);
        auto it_front = m.lower_bound(key);
        int a = abs(key - it_front->first);
        int b = abs(key - it_back->first);
        // 1 Key Value 데이터 추가
        if(num == 1) {
            cin >> value;
            m[key] = value;
        }
        // 2 Key Value 데이터 변경
        else if(num == 2) {
            cin >> value;
            if(a <= K || b <= K) {
                if(a == b) continue;
                else if(a < b) m[it_front->first] = value;
                else if(a > b) m[it_back->first] = value;
                else continue;
            }
        }
        // 3 Key 데이터 검색, 조건 만족 키
        else if(num == 3) {
            if(a <= K || b <= K) {
                if(a == b) cout << "?\n";
                else if (a < b) cout << it_front->second << "\n";
                else if (a > b) cout << it_back->second << "\n";
                else cout << "-1\n";
            }
        }
    }
}