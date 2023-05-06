#include <iostream>
#include<string>
#include <vector>

using namespace std;

int main() {

	int size = 0;

	int N;
	cin >> N;
	cin.ignore(); //https://velog.io/@jxlhe46/C-getline-%ED%95%A8%EC%88%98
	vector<int>stack(N);
	vector<string>Cmd(N);

	for (int i = 0; i < N; i++) {
		getline(cin, Cmd[i]);
	}
	for (int i = 0; i < N; i++) {
		if (Cmd[i].substr(0, 4) == "push") {
			int num = stoi(Cmd[i].substr(5, 6));
			stack[size] = num;
			size++;
		}
		else if (Cmd[i] == "pop") {
			if (size == 0) { cout << "-1" << endl; continue; }
			cout << stack[size - 1] << endl;
			size--;
		}
		else if (Cmd[i] == "size") {
			cout << size << endl;
		}
		else if (Cmd[i] == "empty") {
			cout << (size == 0) << endl;
		}
		else if (Cmd[i] == "top") {
			if (size == 0) { cout << "-1" << endl; continue; }
			cout << stack[size - 1] << endl;
		}
	}
}