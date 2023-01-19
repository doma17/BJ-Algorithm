#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool comp(pair<int, int>& a, pair<int, int>& b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

int main() {
    fastio;
    map<int, int> m;
    int N, S ,T;
    
    cin >> N;
    while(N--) {
        cin >> S >> T;
        if(m.find(S) != m.end() && m[S] > T) m[S] = T;
        else if(m.find(S) == m.end()) m[S] = T;
    }
}