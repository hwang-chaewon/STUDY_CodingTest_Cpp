#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    map<int, int>m;
    vector<int> num(N);
    vector<int> rst(N);
    stack<int> st;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
        if (m.find(num[i]) != m.end()) {
            m[num[i]]++;
        }
        else {
            m.insert({ num[i],1 });
        }
    }
    for (int i = 0; i < N; i++) {
        if (m.find(num[i]) != m.end()) {
            num[i] = m[num[i]];
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        int ngf = -1;
        while (!st.empty() && num[i] >= st.top()) { st.pop(); }
        if (!st.empty()) { ngf = st.top(); }
        st.push(num[i]);
        rst[i] = ngf;
    }
    for (int i = 0; i < N; i++) {
        cout << rst[i] << " ";
    }

    return 0;
}