#include<iostream>
#include<vector>

using namespace std;

int record[1001] = {0,};
int maxn = 0;

int calc(int N, vector<int> p_i) {
    if (N == 0) { return 0; } //base condition: f(0)
    if (N == 1) { return p_i[1]; } //base condition: p_1

    for (int i = 1; i <= N; i++) {
        if (record[N - i] == 0) {
            record[N - i] = calc(N - i, p_i); //recursion
        }
        maxn = (maxn > p_i[i] + record[N - i]) ? maxn : p_i[i] + record[N - i];
    }
    return maxn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<int> p_i(N + 1);
    for (int i = 1; i <= N; i++) { //index==i 되도록, p_0이 0이도록
        cin >> p_i[i];
    }

    cout << calc(N, p_i);

    return 0;
}