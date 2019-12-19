#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector <int>& v){
    int temp;
    for(int i = 0; i < v.size() / 2; i++){
        temp = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = temp;
    }
        
}

int main(){
    vector <int> numbers = {3, 5, 7, 1, 9};
    Reverse(numbers);
    for(int i = 0; i < numbers.size(); i++)
        cout << numbers[i];
    return 0;
}