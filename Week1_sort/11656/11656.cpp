#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool comp(string a, string b) {
    int i = 0;
    while(true) {
        if(a[i] != b[i]) return a[i] < b[i];
        i++;
    }
}

int main() {
    fastio;

    vector<string> v;
    string input;
    cin >> input;

    for(int i = 0; i < input.length(); i++) {
        v.push_back(input.substr(i, input.length())); 
    }

    sort(v.begin(), v.end(), comp);
    
    vector<string>::iterator it;
    for(it = v.begin(); it != v.end(); it++) cout << *it << "\n";
}