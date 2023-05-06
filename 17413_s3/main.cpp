#include <iostream>
#include <string>
#include<stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str;
    getline(cin, str);

    stack<char> rev;
    bool brac = false;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '<') { brac = true; }
        if (str[i] == '>') { brac = false; }
        if (brac == true or str[i] == '>') { cout << str[i]; }
        else {
            if (str[i] !=' ') {
                rev.push(str[i]);
            }
        }
        if ((str[i] ==' ' or i==str.size()-1 or str[i+1]=='<') and (brac==false)) {
            int size = rev.size();
            for (int k = 0; k < size; k++) {
                cout << rev.top();
                rev.pop();
            }
            if (str[i] == ' ') { cout << ' '; }
        }
    }
    return 0;
}