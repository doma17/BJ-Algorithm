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
    map<int, int> m; int key, value;
    for(int i = 0; i < N; i++) {
        cin >> key >> value;
        m[key] = value;
    }

    int num;
    for(int i = 0; i < M; i++) {
        cin >> num >> key;
        // 1 Key Value 데이터 추가
        if(num == 1) {
            cin >> value;
            if(m.find(key) == m.end())m[key] = value;
            continue;
        }

        // 가장 가까운 key값을 탐색
        int cal_num = 1; 
        while(m.find(key) == m.end()) {

            // auto it = m.lower_bound(key)

            // K범위를 넘어감 or 탐색실패 -> -1을 저장
            if(cal_num > K) { 
                key = -1; 
                break;
            }
            // 같은 범위 안의 해당하는 키가 두개 이상 존재
            if(m.find(key - cal_num) != m.end() && m.find(key + cal_num) != m.end()) {
                key = 0;
                break;
            }
            else if(m.find(key - cal_num) != m.end()) {
                key -= cal_num;
                break;
            }
            else if (m.find(key + cal_num) != m.end()){
                key += cal_num;
                break;
            }
            cal_num++;
        }
        
        if(num == 2) {
            cin >> value;
            if(key > 0) m[key] = value;
        }
        else { // num == 3
            if(key == -1) cout << "-1\n";
            else if(key == 0) cout << "?\n";
            else cout << m[key] << "\n";
        }
    }
}