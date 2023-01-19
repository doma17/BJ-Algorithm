#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

map<ll, ll> A;
ll N, P, Q, X, Y;
ll func(ll n) {
    if(n <= 0) return 1;
    if(A.count(n)) return A[n];
    return A[n] = func(n / P - X) + func(n / Q - Y);
}

int main() {
    fastio;
    cin >> N >> P >> Q >> X >> Y;

    A[0] = 1;
    cout << func(N) << "\n";
}