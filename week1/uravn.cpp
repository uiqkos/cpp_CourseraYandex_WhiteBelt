#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 0){
        if(b == 0)
            return 0;
        cout << -(c / b);
        return 0;
    }
    int d = (b*b) - (4 * a * c);
    //float f = (-b - sqrt(d)) / (2 * a);
    //cout << f << endl;
    if(d < 0)
        return 0;
    //int t = (d == 0) ? -b / 2 * a : (-b + sqrt(d)) / 2 * a;
    if(d == 0)
        cout << (double)(-b) / (2 * a);
    else 
        cout <<  (double)(-b + sqrt(d)) / (2 * a) << ' ' <<  (double)(-b - sqrt(d)) / (2 * a);
    system("pause");
    return 0;
}