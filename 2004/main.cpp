#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    if (2 * M > N) { M = N - M; }
    int two = 0; int five = 0;

    for (int i = 1; i <= M; i++) {
        if(i%2==1 && i%5!=0){continue;}
        int j = i;
        while (j % 2 == 0) { two--; j /= 2; }
        while (j % 5 == 0) { five--; j /= 5; }
    }
    for (int i = N-M+1; i <= N; i++) {
        if(i%2==1 && i%5!=0){continue;}
        int j = i;
        while (j % 2 == 0) { two++; j /= 2; }
        while (j % 5 == 0) { five++; j /= 5; }
    }


    cout << min(two, five);
    return 0;
}