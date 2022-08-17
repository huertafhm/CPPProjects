#include <iostream>

using namespace std;

int fib(int n){

    int f[n+1];
    int i;
    f[0] = 0;
    f[1] = 1;
    for (i = 2; i <= n; i++){
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int main(){
    int fibIn;
    int result;

    cout<<"Which number? ";
    cin >> fibIn;

    result = fib(fibIn);
    cout<<"Fibonacci number "<<fibIn<<" is: "<<result<<endl;
    printf("aaa hello");
}