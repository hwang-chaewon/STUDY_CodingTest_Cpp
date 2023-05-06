#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include <math.h>

using namespace std;

int main() {
	int N;
	cin >> N; 
	cin.ignore();
	vector<string> stc(N);
	int max_len=0; //chatGPT
	//vector<vector<string>> wd(N, vector<string>(1000));    //chatGPT: 여기서 1000으로 초기화하지 말기
	for (int i = 0; i < N; i++) {
		getline(cin, stc[i]);
		max_len=max(max_len, (int)stc[i].length()); //chatGPT
	}
	vector<vector<string>> wd(N, vector<string>(max_len));
	for (int i = 0; i < N; i++) {
		stringstream ss(stc[i]);
		string buffer;
		int j = 0;
		while (getline(ss, buffer, ' ')) {
			wd[i][j]=buffer;
			reverse(wd[i][j].begin(), wd[i][j].end());
			j++;
		}
		for (int k = 0; k < j; k++) {
			cout << wd[i][k] << " ";
		}
		cout << endl;
	}
}