#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    cout << min(min(a, b), c);
    system("pause");
    return 0;
}