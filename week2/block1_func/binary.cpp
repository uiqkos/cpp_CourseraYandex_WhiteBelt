#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int a;
    string s;
    cin >> a;
    for(int i = floor(sqrt(a)); i >= 0; i--){
        //cout << (int)pow(2.0, i) << endl;
        if(a - pow(2.0, i) < 0)
            s += '0';
        else{
            s += '1';
            a -= pow(2.0, i);
        }
        //s += (int)(a % (int)pow(2.0, i)) + '0';
    }    
    string result;
    int i;
    for(i = 0; i < s.length(); i++)
        if(s[i] != '0')
            break;
    //cout << i << ' ' << s <<  endl;
    s.erase(s.begin(), s.begin() + i);
    cout << s;
    system("pause");
    return 0;
}