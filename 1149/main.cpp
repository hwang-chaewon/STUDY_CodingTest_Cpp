#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    int sum = 0;
    int idx = 4; //(제외할)바로 직전의 index 초기화
    int cost;

    for (int i = 0; i < N; i++) {
        int min = 1001;
        //i번째 집의 RGB 비용 입력받기
        for (int j = 0; j < 3; j++) {
            cin >> cost;
            if (j == idx) { continue; } //직전의 index는 넘기기
            if (cost < min) { min = cost; idx = j; } //min 값과 idx update
        }
        sum += min;
    }
    cout << sum;

    return 0;
}