#include<iostream>
#include<vector>
using namespace std;

int record[12];

int calc(int a) {
    if (a == 0) { return 0; }
    if (a == 1) { return 1; }
    if (a == 2) { return 2; }
    if (a == 3) { return 4; } //남의 코드를 보고 이걸 덧붙이긴 했는데 왜 필요한지 모르겠음....1,2,3으로 표현하는 거니까 그거 자체는 정의해줘야 하는 그런건가??
    if (record[a] != 0) { return record[a]; }
    return record[a] = calc(a - 1) + calc(a - 2) + calc(a - 3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    vector<int> test(T);

    for (int i = 0; i < T; i++) {
        cin >> test[i];
    }
    for (int i = 0; i < T; i++) {
        cout << calc(test[i]) <<endl;
    }

    return 0;
}