#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<int> perm(N);

    for (int i = 0; i < N; i++) {
        cin >> perm[i];
    }

    int i = N - 1;
    if (i == 0) { cout << "-1";  return 0; } //N==1일 때를 대비
    while (perm[i] < perm[i - 1]) {
        i--;
        if (i == 0) { cout << "-1";  return 0; }
    }
    int min = max_element(perm.begin()+i, perm.end())- perm.begin(); //여기 보기
    int j = i;
    for (; j < N; j++) {
        if (perm[i-1] < perm[j] && perm[j] < perm[min]) { min = j; }
    }
    swap(perm[i - 1], perm[min]); //여기서 에러가 남
    sort(perm.begin() + i, perm.end());

    for (int i = 0; i < N; i++) {
        cout << perm[i] << ' ';
    }

    return 0;
}