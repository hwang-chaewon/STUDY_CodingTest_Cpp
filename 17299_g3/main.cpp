#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<int> num(N);
    vector<int> a(1000001);
    vector<int> rst(N);
    stack<int> st;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
        a[num[i]]++;
    }

    for (int i = N - 1; i >= 0; i--) {
        int ngf = -1;
        while (!st.empty() && a[num[i]] >= a[st.top()]) {
            st.pop();
        }
        if (!st.empty()) {
            ngf = st.top();
        }
        st.push(num[i]);
        rst[i] = ngf;
    }
    for (int i = 0; i < N; i++) {
        cout << rst[i] << " ";
    }

    return 0;
}