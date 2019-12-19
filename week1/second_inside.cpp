#include <iostream>
using namespace std;

int main(){
    string s;
    int v = -1;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'f')
            v++;
        if(v == 1){
            v = i + 1;
            break;
        }
    }
    cout << v - 1;
    system("pause");
    return 0;
}