#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
	int N;
	cin >> N; cin.ignore();
	vector<string> stack(N);
	for (int i = 0; i < N; i++) {
		cin >> stack[i];
	}
	for (int i = 0; i < N; i++) {
		int size = 0;
		int rightsize = 0; //상쇄된, 또는 size=0인 상태에서 )들어올 경우를 대비해 변수를 하나 더 둠
		for (int j = 0; j < stack[i].size(); j++) {
			if (stack[i].at(j) == '(') {
				size++;
			}
			else if (size != 0 && stack[i].at(j) == ')') {
				size--;
			}
			else { rightsize++; }
		}
		if (size == 0 && rightsize==0) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	return 0;
}