#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int input[100000];
int N = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    //테스트 케이스 입력받기
    while (1) {
        cin >> input[N];
        if (input[N] == 0) { break; }
        N++;
    }

    //모든 테스트 케이스에 대해 반복
    for (int i = 0; i < N; i++) {
        //1~i까지 배열 생성, 초기화
        vector<int> dec(input[i] + 1);
        for (int j = 1; j <= input[i]; j++) {
            dec[j] = j; //'index==값' 되도록
        }

        //소수 구하기
        for (int j = 2; j <= sqrt(input[i]); j++) {
            if (dec[j] == 0) { continue; } //0이라면 소수가 아니라 제거된 것으므로 이것의 배수로 제거할 수는 없음

            //소수의 배수인 자리를 0으로 만들기
            int k = 2;
            while (dec[j] * k <= input[i]) {
                dec[dec[j] * k] = 0;
                k++;
            }
        }
        //1과 2는 소수에서 제외하기
        dec[1] = 0; dec[2] = 0;

        //소수만 뽑아내기
        for (int j = 0; j < dec.size(); j++) {
            if (dec[j] == 0) { dec.erase(dec.begin()+j); }
        }

        //출력
        int a = 0; int b = dec.size() - 1;
        char prev = 'b';
        
        while (a < b) {
            if (dec[a] + dec[b] == input[i]) {
                cout << input[i] << " = " << dec[a] << " + " << dec[b] << "\n";
                break;
            }

            if (prev == 'a') {
                a++; prev = 'b';
            }
            else if (prev == 'b') {
                b--; prev = 'a';
            }
        }
        if (a == b) { cout << "Goldbach's conjecture is wrong.\n"; }
    }

    return 0;
}