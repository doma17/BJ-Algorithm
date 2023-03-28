#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

double time_calc(int node1_time, int node2_time, int vertex) {
    double time;
    double length = vertex;
    for(time = 0; time < abs(node1_time - node2_time);) {
        length--;
        time++;
        if(time >= vertex) return time;
    }
    cout << time << "\n";
    cout << length / 2 << "\n";
    return (time + length / 2);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << time_calc(a, b, c) << "\n";
}