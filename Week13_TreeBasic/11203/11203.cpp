#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
typedef long long int ll;
#define MAX 100001

int N;
string str;
bool visited[MAX];
vector<int> v[MAX];
int root, ans;

int find(int x) {
	return -1;
}

int main() {
	fastio;
    cin >> N;
    cin >> str;
    // if(str == "")
        cout << pow(2, N + 1) - 1 << "\n"; 
    // else
    //     cout << find(root) << "\n";
}