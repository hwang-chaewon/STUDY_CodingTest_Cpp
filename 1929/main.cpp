#include<iostream>
#include<math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int M, N;
    cin >> M >> N;

    bool A[1000001] = { 0 };

    for (int i = 2; i<= sqrt(N); i++) {
        int j = 2;
        while (i * j <= N) {
            A[i * j] = 1;
            j++;
        }
    }
    for (int i = M; i <= N; i++) {
        if (A[i] != 1 && i != 1) {
            cout << i << "\n";
        }
    }
    return 0;
}