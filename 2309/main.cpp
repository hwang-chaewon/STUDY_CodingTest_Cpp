#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int height[9] = { 0 };
    int sum_ = 0;
    for (int i = 0; i < 9; i++) {
        cin >> height[i];
        sum_ += height[i];
    }
    for (int i = 0; i < 9; i++) {
        int sum = sum_;
        sum = sum - height[i];
        for (int j = 0; j < 9; j++) {
            if (i== j) { continue; }
            if (sum-height[j] == 100) {
                height[i] = height[j] = 0;
                sort(height, height + 9);
                for (int k = 2; k < 9; k++) {
                    cout << height[k] << "\n";
                }
                return 0;
            }
        }
    }
}