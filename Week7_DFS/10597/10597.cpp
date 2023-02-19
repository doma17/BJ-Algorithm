#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int

string str;
int length;
bool visited[51];
vector<int> v;
int max_value;

void dfs(int cnt) {
    if(cnt == length) {
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
        exit(0); // return이 아닌 exit으로 코드 전체를 종료시킨다.
    }

    string tmp_str = "";
    int tmp_int = 0;
    for(int i = cnt; i <= cnt + 1; i++) {
        tmp_str += str[i];
        tmp_int = stoi(tmp_str);
        // 현재 인덱스의 str에서 뽑은 수가 아래의 조건에 부합하다면
        // 다음 인덱스로 넘어가서 두 자리의 숫자를 확인하게 된다.
        if(tmp_int > max_value || visited[tmp_int]) continue;

        v.push_back(tmp_int);
        visited[tmp_int] = true;
        dfs(i + 1);
        v.pop_back();
        visited[tmp_int] = false;
    }
}

int main() {
    fastio;
    cin >> str;
    length = (int)str.size();

    // https://hibee.tistory.com/179 참조
    if(length < 10)
        max_value = length;
    else
        max_value = (length - 9) / 2 + 9;

    dfs(0); 
}