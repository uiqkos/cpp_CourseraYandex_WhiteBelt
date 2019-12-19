#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MoveStrings(vector <string>& source, vector <string>& destination){
    for(auto c : source)
        destination.push_back(c);
    source.clear();
}

int main(){
    vector <string> source = {"a", "b"}, destination = {"lol", "gg"};
    MoveStrings(source, destination);
    for(int i = 0; i < destination.size(); i++)
        cout << destination[i];
    return 0;
}