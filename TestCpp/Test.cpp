#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<pair<int, int>> lastDigit_numbers(numbers.size());
    cout << "init \n";
    for(int index = 0; index < numbers.size(); index++) {
        int cnt_num = numbers[index];

        cout << "cnt_num: "<< cnt_num << "\n";

        while(cnt_num < 10) {
            cnt_num = cnt_num / 10;
        }
        lastDigit_numbers[index] = make_pair(cnt_num, numbers[index]);
    }
    
    sort(lastDigit_numbers.begin(), lastDigit_numbers.end(), comp);
    
    for(int index = 0; index < numbers.size(); index++) {
        answer += to_string(lastDigit_numbers[index].second);
    } 
    return answer;
}

int main() {
    cout << 10/10;
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cout << "cin\n";
        cin >> v[i];
    }

    cout << solution(v);
}