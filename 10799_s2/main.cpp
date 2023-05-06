#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string brac;
    cin >> brac;

    stack<char> stk;
    int count = 0;

    for (int i = 0; i < brac.size(); i++) {
        if (brac[i] == '(') {
            stk.push(brac[i]);
        }
        else {
            stk.pop();
            if (brac[i-1] == '(') { //레이저: 자르기
                count += stk.size();
            }
            else { count++; } //non레이저: 막대 끝이 하나 생김
        }
    }
    cout << count;

    return 0;
}