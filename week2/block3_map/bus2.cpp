#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    map <int, vector<string>> bus_db;
    int N, n, count = 1;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> n;        
        vector <string> temp_vector(n);
        //cout << temp_vector.size();
        for(int j = 0; j < n; j++){
            cin >> temp_vector[j];
        }
        for(auto c : bus_db)
            if(c.second == temp_vector){
                n = 0;
                cout << "Already exists for " << c.first << endl;
                break;
            }
        if(n){
            bus_db[count] = temp_vector;
            cout << "New bus " << count << endl;
            count++;            
        }

    }

    return 0;
}
/*
4
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino
*/