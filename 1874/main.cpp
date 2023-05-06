#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin>>N; cin.ignore();
    vector<int> stack(N+1,-1);
    vector<int> Rst(N+1), Ans(N+1);
    vector<char> out;
    int size=0;

    for(int i=1;i<=N;i++){
        cin>>Ans[i];
        if(stack[size]!=-1){
            if(Rst[size]!=Ans[size]){cout<<"NO"; return 0;}
            size--;
            out.push_back('-');
        }else{
            for(int j=size;j<Ans[i];j++){
                stack[size]=j;
                out.push_back('+');
                size++;
            }
        }
    }
    for (char i:out) {
        cout << i << endl;
    }
    return 0;
}