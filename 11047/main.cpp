#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> coin(N);
    int count = 0;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        if (coin[i] <= K) { K -= coin[i]; count++; i++; }
        if (K == 0) { break; }
    }
    cout << count;
    return 0;
}