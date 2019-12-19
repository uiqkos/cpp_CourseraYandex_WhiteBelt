#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<string> sort_at_time(vector<string> sourse, vector<string> result){
    for(int i = 0; i < sourse.size(); i++)
        if(find(result.begin(), result.end(), sourse[i]) == result.end())
            sourse.erase(sourse.begin() + i);
    return sourse;
}

int main(){
    map <string, vector <string>> bus_db;
    string command, bus, stop;
    vector<string> positions, res;
    int stop_count;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> command;
        if(command == "NEW_BUS"){
            cin >> bus;
            cin >> stop_count;
            bus_db[bus].resize(stop_count);
            for(int i = 0; i < stop_count; i++)
                cin >> bus_db[bus][i];            
            positions.push_back(bus);
        }
        else if(command == "BUSES_FOR_STOP"){
            cin >> stop;
            int count = 0;            
            for(auto c : bus_db)
                if(find(c.second.begin(), c.second.end(), stop) != c.second.end())
                    count++;
            if(!count)
                cout << "No stop" << endl;
            else{                
                for(auto c : bus_db)
                    if(find(c.second.begin(), c.second.end(), stop) != c.second.end())
                        res.push_back(c.first);
                res = sort_at_time(positions, res);
                for(const auto& c : res)
                    cout << c << ' ';
                res.clear();
                cout << endl;
            }
        }
        else if(command == "STOPS_FOR_BUS"){
            cin >> bus;
            int count = 0;
            if(bus_db.find(bus) == bus_db.end())
                cout << "No bus" << endl;
            else{
                //cout << "Bus " << bus << ": ";
                for(auto c : bus_db[bus]){
                    cout << "Stop "<< c << ": ";
                    for(auto w : bus_db){
                        if(find(w.second.begin(), w.second.end(), c) != w.second.end() && w.first != bus){
                            cout << w.first << ' ';
                            count++;
                        }
                                               
                    }
                    if(!count)
                        cout << "no interchange"; 
                    count = 0;
                    cout << endl;
                    
                }
                cout << endl;
            }
        }
        else if(command == "ALL_BUSES"){
            if(bus_db.size() == 0)
                cout << "No buses" << endl;
            else{                
                for(auto c : bus_db){
                    cout << "Bus " << c.first << ": ";
                    for(auto w : c.second)
                        cout << w << ' ';
                    cout << endl;
                }
            }
        }
    }
    system("pause");
    return 0;
}