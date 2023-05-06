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
		int rightsize = 0; //����, �Ǵ� size=0�� ���¿��� )���� ��츦 ����� ������ �ϳ� �� ��
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