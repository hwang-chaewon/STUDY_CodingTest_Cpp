#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int A,B;
    cin>>A>>B;
    int maxY=1;
    int a=A; int b=B;
    int i=2;

    while(i<=min(A,B)){
        while(a%i==0 && b%i==0){
            maxY*=i; 
            a/=i; b/=i;
        }
        i++;
    }
    int maxB=maxY*a*b;
    cout<<maxY<<"\n"<<maxB;

    return 0;
}