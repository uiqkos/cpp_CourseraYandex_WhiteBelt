#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    while(a > 0 && b > 0){
        if(a > b)
            a = a % b;
        else 
            b = b % a;
    }
    cout << a + b;
    /*
    if(a == 0)
        cout << b;
    else if(b == 0)
        cout << a;
    if(a == 1)
        cout << a;
    else if(b == 1)
        cout << b;
    for(int i = min(a, b); i > 0; i--)
        if(a % i == 0 && b % i == 0){
            cout << i;
            break;
        }*/
    system("pause");
    return 0;
}