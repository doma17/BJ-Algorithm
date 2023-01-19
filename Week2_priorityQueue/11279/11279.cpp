#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    priority_queue<int> q;
    int N, num;
    cin >> N;
    while(N--) {
        cin >> num;
        if(num == 0) {
            if(q.empty()) cout << "0\n";
            else {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else q.push(num);
    }    
}