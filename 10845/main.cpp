#include<iostream>
#include<vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N; cin.ignore();

    vector<string> c(N);
    vector<int> qu(N);
    int size = 0, start = 0;
    for (int i = 0; i < N; i++) {
        getline(cin, c[i]);
    }
    for (int i = 0; i < N; i++) {
        string cmd = c[i].substr(0, 2);
        if (cmd == "pu") {
            qu[start + size] = stoi(c[i].substr(5));
            size++;
        }
        else if (cmd == "po") {
            if (size == 0) { cout << "-1" << endl; }
            else {
                cout << qu[start] << endl;
                start++;
                size--;
            }
        }
        else if (cmd == "si") {
            cout << size << endl;
        }
        else if (cmd == "em") {
            if (size == 0) { cout << "1" << endl; }
            else { cout << "0" << endl; }
        }
        else if (cmd == "fr") {
            if (size == 0) { cout << "-1" << endl; }
            else { cout << qu[start] << endl; }
        }
        else if (cmd == "ba") {
            if (size == 0) { cout << "-1" << endl; }
            else { cout << qu[start + size - 1] << endl; }
        }
    }
    return 0;
}