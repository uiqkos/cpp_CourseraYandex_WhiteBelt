#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int position = 0;
    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> days(31);
    int n;
    cin >> n;
    string cmd;
    for(int i = 0; i < n; i++){
        cin >> cmd;
        if(cmd == "ADD"){
            int arg1; 
            string arg2;
            cin >> arg1 >> arg2;
            days[arg1 - 1].push_back(arg2);/*
            for(const auto& c : days)
                for(const auto& w : c)
                    cout << w;*/
        }
        else if(cmd == "NEXT"){
            vector<vector<string>> temp_vector = days;
            if(position == 11)
                position = -1;
            if(months[++position] >= days.size()){
                temp_vector.resize(months[position]);
                //temp_vector.insert(end(temp_vector), begin(days) + mounths[position], end(days));
                //cout << temp_vector.size();
            }
            //cout << position << endl;
            else{
                temp_vector.resize(months[position]);
                int len = days.size() - temp_vector.size();
                for(int i = 0; i < len; i++)
                    temp_vector[temp_vector.size()- 1].insert(end(temp_vector[temp_vector.size()- 1]), begin(days[days.size() - i - 1]), end(days[days.size() - i - 1]));
            }
            //cout << temp_vector[temp_vector.size() - 1];
            /*for(const auto& c : temp_vector)
                for(const auto& w : c)
                    cout << w;
                    */
            days = temp_vector;
            temp_vector.clear();
        }
        else if(cmd == "DUMP"){
            int day;
            cin >> day;
            cout << days[day - 1].size() << ' ';
            for(const auto& c : days[day - 1])
                cout << c << ' ';
            cout << endl;
        }
    }
    system("pause");
    return 0;
}
/*
add
*/