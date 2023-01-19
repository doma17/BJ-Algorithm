#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;

    map<string, double> m;
    string input; double n = 0;
    while(getline(cin, input)) {
        if(m.find(input) != m.end()) m[input]++;
        else m[input] = 1;
        n++;
    }

    cout << fixed;
    cout.precision(4);
    for(auto x : m) {
        double val = (x.second * 100) / n;
        cout << x.first << " " << val << "\n";
    }
}