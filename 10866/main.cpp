#include<iostream>
#include<vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N; cin.ignore();

    vector<string> c(N);
    vector<int> dq(N);
    int size = 0, start = 0;
    for (int i = 0; i < N; i++) {
        getline(cin, c[i]);
    }
    for (int i = 0; i < N; i++) {
        string cmd = c[i].substr(0, 1);
        string cmd2 = c[i].substr(2, 4);
        if (cmd2 == "sh_f") {
            for(int i=(start+size);i>start;i--){
                dq[i]=dq[i-1];
            }
            dq[start] = stoi(c[i].substr(11));
            size++;
        }
        else if (cmd2 == "sh_b") {
            dq[start + size] = stoi(c[i].substr(10));
            size++;
        }
        else if (cmd2 == "p_fr") {
            if (size == 0) { cout << "-1" << endl; }
            else {
                cout << dq[start] << endl;
                start++;
                size--;
            }
        }
        else if (cmd2 == "p_ba") {
            if (size == 0) { cout << "-1" << endl; }
            else {
                cout << dq[start+size-1] << endl;
                size--;
            }
        }
        else if (cmd == "s") {
            cout << size << endl;
        }
        else if (cmd == "e") {
            if (size == 0) { cout << "1" << endl; }
            else { cout << "0" << endl; }
        }
        else if (cmd == "f") {
            if (size == 0) { cout << "-1" << endl; }
            else { cout << dq[start] << endl; }
        }
        else if (cmd == "b") {
            if (size == 0) { cout << "-1" << endl; }
            else { cout << dq[start + size - 1] << endl; }
        }
    }
    return 0;
}