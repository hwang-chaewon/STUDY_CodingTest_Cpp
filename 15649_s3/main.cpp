#include <iostream>
using namespace std;

int N,M;
int rst[8]={0};
bool visited[9]={0};

void pick(int num){ 
    if(num==M){
        for(int i=0;i<M;i++){
            cout<<rst[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            visited[i]=1;
            rst[num]=i;
            pick(num+1);
            visited[i]=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N >> M;
    pick(0);

    return 0;
}