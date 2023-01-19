#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int T;
    cin >> T;
    while(T--) {
        multiset<int> ms;
        int K, num, size = 0; char c; 
        cin >> K;

        for(int i = 0; i < K; i++) {
            cin >> c >> num;
            if(c == 'I') {
                size++;
                ms.insert(num);
            }
            else if(size > 0){ // c == D
                size--;
                if(num == -1) ms.erase(ms.begin());
                else if(num == 1) {
                    auto it = ms.end();
                    it--;
                    ms.erase(it);
                }
            }
        }

        if(ms.empty()) cout << "EMPTY\n";
        else {
            auto it = ms.end();
            it--;
            cout << *it << " " << *ms.begin() << "\n";
        }
    }
}