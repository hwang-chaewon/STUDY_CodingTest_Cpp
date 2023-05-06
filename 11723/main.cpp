#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N; cin.ignore();
    deque<int> set;

    deque<int> check;

    string c;
    int num;

    for (int i = 0; i < N; i++) {
        getline(cin, c);
        string cmd=c.substr(0, 2);
        if (cmd== "ad") {
            num = stoi(c.substr(4));
            if (!count(set.begin(), set.end(), num)) { //존재안하면
                set.push_back(num); //넣기
            }
        }
        else if (cmd== "re") {
            num = stoi(c.substr(7));
            if (count(set.begin(), set.end(), num)) { //존재하면
                set.erase(remove(set.begin(), set.end(), num), set.end()); //제거
            }
        }
        else if (cmd== "ch") {
            num = stoi(c.substr(6));
            if (count(set.begin(), set.end(), num)) { //존재하면
                check.push_back(1);
            }
            else {check.push_back(0);}
        }
        else if (cmd== "to") {
            num = stoi(c.substr(7));
            if (count(set.begin(), set.end(), num)) { //존재하면
                set.erase(remove(set.begin(), set.end(), num), set.end()); //제거
            }
            else { set.push_back(num); }
        }
        else if (cmd== "al") {
            set.resize(0);
            for (int i = 1; i <= 20; i++) {
                set.push_back(i);
            }
        }
        else if (cmd== "em") {
            set.resize(0);
        }
    }
    for(int i=0;i<check.size();i++){
        cout<<check[i]<<"\n";
    }
    return 0;
}