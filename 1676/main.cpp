#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    int two=0, five = 0;
    for (int j = 2; j <= N; j++) {
        int d = 2;
        int i = j;
        while (i > 1) {
            if (i % d == 0) {
                i = i / d;
                if (d == 2) { two++; }
                if (d == 5) { five++; }
            }
            else { d++; }
        }
    }
    cout << min(two, five);

    return 0;
}