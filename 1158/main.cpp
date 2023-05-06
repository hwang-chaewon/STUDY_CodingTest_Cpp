#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, start;
    cin >> N >> start;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        A[i] = i + 1;
    }
    int place = start - 1;
    for (int i = 0; i < N; i++) {
        B[i] = A[place];
        A.erase(A.begin() + place);
        for (int j = 0; j < start-1; j++) {
            if (place >= A.size()) { place = place - A.size(); }
            place++;
            if (place >= A.size()) { place = place - A.size(); }
        }
    }
    cout << "<";
    for (int i = 0; i < N - 1; i++) {
        cout << B[i] << ", ";
    }
    cout << B.back() << ">\n";

    return 0;
}