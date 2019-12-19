#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct cell{
    bool isWorry = 0;
};


int main(){
    vector <cell> list;
    cell temp;
    int n, a;
    string c;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == "WORRY"){
            cin >> a;
            list[a].isWorry = 1;
        }
        else if(c == "QUIET"){
            cin >> a;
            list[a].isWorry = 0;
        }
        else if(c == "COME"){
            cin >> a;
            if(a > 0)
                for(int i = 0; i < a; i++)
                    list.push_back(temp);   
            else      
                for(int i = 0; i < a * (-1); i++)
                    list.pop_back();     
        }        
        else if(c == "WORRY_COUNT"){
            int count = 0;
            for(int i = 0; i < list.size(); i++)
                count += list[i].isWorry;
            cout << count << endl;
        }
            
    }
    return 0;
}