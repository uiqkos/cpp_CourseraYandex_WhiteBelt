#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main(){
    map <int, set<string>> bus_db;
    int N, n, count = 1;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> n;        
        set <string> temp_set;
        string temp;
        //cout << temp_vector.size();
        for(int j = 0; j < n; j++){
            cin >> temp;
            temp_set.insert(temp);
        }
        for(auto c : bus_db)
            if(c.second == temp_set){
                n = 0;
                cout << "Already exists for " << c.first << endl;
                break;
            }
        if(n){
            bus_db[count] = temp_set;
            cout << "New bus " << count << endl;
            count++;            
        }
        

    }

    return 0;
}
/*
5
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino
2 Kokoshkino Kokoshkino

New bus 1
New bus 2
Already exists for 1
Already exists for 1
Already exists for 2
*/