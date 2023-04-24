#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    string cmd; cin >> cmd; //수식 받기

    //입력 숫자 받기
    vector<int> num; int n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        num.push_back(n);
    }

    //계산
    stack<double> stk;
    for (int i = 0; i < cmd.size(); i++) {
        double A, B;
        //연산자 나오면 2개 pop해 계산해서 결과값 push 
        if (cmd[i] == '+') {
            B = stk.top(); stk.pop();
            A = stk.top(); stk.pop();
            stk.push(A + B);
        }
        else if (cmd[i] == '-') {
            B = stk.top(); stk.pop();
            A = stk.top(); stk.pop();
            stk.push(A - B);
        }
        else if (cmd[i] == '*') {
            B = stk.top(); stk.pop();
            A = stk.top(); stk.pop();
            stk.push(A * B);
        }
        else if (cmd[i] == '/') {
            B = stk.top(); stk.pop();
            A = stk.top(); stk.pop();
            stk.push(A / B);
        }
        else { //피연산자는 push. 다만 char를 double로 바꿔서
            stk.push(double(num[int(cmd[i] - 65)]));
        }
    }
    cout << fixed; cout.precision(2);
    cout << stk.top();
    return 0;
}
