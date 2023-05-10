#include <iostream>
#include <regex>
#include <string>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;

int t;
regex r("[A-F]\?A+F+C+[A-F]\?");
string str;

int main() {
    fastio;
    
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> str;
        cout << (regex_match(str, r) ? "Infected!" : "Good") << "\n";
    }

    return 0;
}