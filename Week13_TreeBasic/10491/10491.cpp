#include <iostream>
#include <regex>
#include <string>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;
#define MAX 100001

string src = "";
regex ans(".*problem.*");

int main() {
	fastio;
    while (true) {
        getline(cin, src);
        transform(src.begin(), src.end(), src.begin(), ::tolower);
        if(regex_match(src, ans)) {
            // FOUND
            cout << "yes" << "\n";
        }
        else {
            // NOT FOUND
            cout << "no" << "\n";
        }
        if(cin.eof() == true) break;
    }
}