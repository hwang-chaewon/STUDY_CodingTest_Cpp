#include<iostream>
#include<vector>
using namespace std;

int N, S;
int input[21] = { 0, };
int cnt = 0;

void combination(int& sum, int R, int depth, int next) {
    if (depth == R) {
        if (sum == S) { cnt++; }
        return;
    }
    for (int i = next; i <= N; i++) {
        sum += input[i];
        combination(sum, R, depth + 1, i + 1);
    }
}

int main() {
    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        cin >> input[i];
    }

    for (int i = 1; i <= N; i++) {
        int sum = 0;
        combination(sum, i, 0, 1);
    }

    cout << cnt;

    return 0;
}