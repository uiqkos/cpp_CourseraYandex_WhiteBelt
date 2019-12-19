#include <iostream>
#include <vector>
#include <map>
//#include <stl_pair.h>
using namespace std;

//struct Person;
/*
int ReturnPosition(int year, vector<pair<int, Person>> v){
    for(int i = 0; i < v.size(); i++)
        if(v[i].first == year)
            return i;
    return -1;
}

struct Person{
private:
    string first_name = "", last_name = "";
    //map<int, Person> ;
    vector<pair<int, Person>> persons;
public:
    Person(string first_name, string last_name){
        this-> first_name = first_name;
        this-> last_name = last_name;
    }
    void ChangeFirstName(int year, string& first_name){
        int position = ReturnPosition(year, persons);
        string temp_string = "";
        if(position != -1)
            get<1>(persons[position]).first_name = first_name;
        else{
            Person temp(first_name, temp_string);
            pair<int, Person> c;
            c.first = year;
            c.second.first_name = temp_string;
            c.second.last_name = temp_string;
            persons.push_back(c);
        }

    }
    void ChangeLastName(int year, const string& last_name){
        persons[year].last_name = last_name;
    }
    string GetFullName(int year){
        int position = -1;
        for(const auto& c : persons){
            if(c.first == year){
                position = 1;                
                string temp_first_name, temp_last_name;
                int v = 0;
                for(const auto& i : persons){
                    if(i.second.first_name != "" && temp_first_name.length() == 0)
                        temp_first_name = persons[i].second.first_name;
                    if(i.second.last_name != "" && temp_last_name.length() == 0)
                        temp_last_name = persons[i].second.last_name;
                    if(!temp_first_name.length() && !temp_last_name.length()){
                        cout << temp_first_name << " " << temp_last_name << endl;
                        break;
                        v = 1;
                    }
                }
                if(!v && !temp_last_name.length()){
                    cout << temp_first_name << "  with unknown last name" << endl; 
                }
                break;
            }

        }
        if(position == -1)
            cout << "Incognito" << end;
        else{

        }
    }
};
*/
struct Person{
private:
    string first_name, last_name;
    map<int, Person> persons;
public:
    void ChangeFirstName(int year, const string& first_name){
        persons[year].first_name = first_name;
    }
    void ChangeLastName(int year, const string& last_name){
        persons[year].last_name = last_name;
    }
    string GetFullName(int year){
        string result_first_name = "", result_last_name = "";
        for(auto c : persons){
            if(c.first > year){
                if(result_first_name == "")
                    return "Incognito";
                else if(result_last_name == "")
                    return result_first_name + " with unknown last name";                
                return result_first_name + " " + result_last_name; 
            }
            if(c.second.first_name != "")
                result_first_name = c.second.first_name;
            if(c.second.last_name != "")
                result_last_name = c.second.last_name;
        }
        return result_first_name + " " + result_last_name; 
    }
};

int main(){
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    system("pause");
    return 0;
}
/*
Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria Sergeeva
Polina Volkova
Appolinaria Volkova
*/