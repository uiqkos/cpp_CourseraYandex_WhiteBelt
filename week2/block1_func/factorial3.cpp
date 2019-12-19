#include <iostream>
using namespace std;

int Factorial(int f){
    int i, j = 1;
    for(i = 1; i <= f; i++)
        j *= i;
    return j;
}

int main(){
    int f;
    cin >> f;
    //cout << factorial(f) << endl;
    int t = 1;
    cout << (int)((f < 0) ? 1 : ((f == 1) ? 1 : ((f == 0) ? 0 : Factorial(f))));
    system("pause");
    return 0;
}