#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define N_ 10001
typedef long long ll;
int a[N_], n, k;  ll lft, rgt;

int main() {
    fastio;
    cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);   // logN
	lft = 0; rgt = a[n - 1];
	while (lft <= rgt) {
		int mid = (lft + rgt) >> 1;
        if(mid == 0) mid = 1;
		int Sum = 0;
		for (int i = 0; i < n; i++)
			Sum += (a[i] / mid);
		if (Sum >= k)
			lft = mid + 1;
		else
			rgt = mid - 1;
	}
	cout << rgt;
}