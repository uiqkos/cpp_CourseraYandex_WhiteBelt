#include <iostream>
#include <vector>
using namespace std;

vector <string> PalindromFilter(vector<string> words, int minLength){
    vector <string> result;
    bool v = 1;
    for(int i = 0; i < words.size(); i++){
        for(int j = 0; j < words[i].length() / 2; j++){
            if(words[i][j] != words[i][words[i].length() - 1 - j]){
                v = 0;
                break;
            }
        }
        if(v == 1 && words[i].length() >= minLength){
            result.push_back(words[i]);
        }
        v = 1;
    }
    return result;
}

int main(){
    vector <string> words = {"code", "bbabb", "bbbb"};
    vector <string> result;
    result = PalindromFilter(words, 3);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << ' ';
    }
    return 0;
}