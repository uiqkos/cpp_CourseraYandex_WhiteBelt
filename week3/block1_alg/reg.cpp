#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <vector>
using namespace std;

bool reg(string c1, string c2){
    for(char& c : c1)
        c = tolower(c);
    for(char& c : c2)
        c = tolower(c);
    return (c1 < c2);
}

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(string& c : v)
        cin >> c;
    sort(v.begin(), v.end(), reg);
    for(auto c : v)
        cout << c << ' ';
    system("pause");
    return 0;
}