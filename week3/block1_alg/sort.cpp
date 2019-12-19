#include <iostream>
#include <algorithm>
#include <vector>
//#include <sdgfdg>
#include <math.h>
using namespace std;

bool module(int i1, int i2){
    return (abs(i1) < abs(i2));
}

int main(){
    int n;
    //cout << "it w";
    cin >> n;
    vector<int> m(n);
    for(int& c : m)
        cin >> c;         
    sort(m.begin(), m.end(), module);
    for(auto c : m)
        cout << c << " ";
    system("pause");
    return 0;
}