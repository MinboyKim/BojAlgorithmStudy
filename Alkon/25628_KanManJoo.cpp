#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;

    int usingBurn=a/2;

    int rst=(usingBurn>b)?b:usingBurn;
    cout<< rst;
    return 0;
}