// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <set>
#include <sstream>
using namespace std;

string error = "";

void peekCheck(istream& stream){
    if(stream.peek() != '-')
        throw invalid_argument("Wrong date format: " + error);
}


class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(const int& year, const int& month, const int& day){
        this->year = year;
        this->month = month;
        this->day = day;
    }

    Date(){
        year = 0;
        month = 1;
        day = 1;
    }
    int GetYear() const{ return year; }
    int GetMonth() const{ return month; }
    int GetDay() const{ return day; }
};

bool operator<(const Date& lhs, const Date& rhs){
    if(lhs.GetYear() == rhs.GetYear()){
        if(lhs.GetMonth() == rhs.GetMonth()){
            return lhs.GetDay() < rhs.GetDay();
        } else return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
    //return lhs.GetMonth() * 1000 + lhs.GetMonth() * 60 + lhs.GetDay() < rhs.GetMonth() * 1000 + rhs.GetMonth() * 60 + rhs.GetDay(); 
}


istream& operator>>(istream& stream, Date& date){
    int year, month, day;
    try{
        if(!(stream >> year))
            throw invalid_argument("Wrong date format: " + error);
        peekCheck(stream);
        stream.ignore(1);
        if(!(stream >> month))
            throw invalid_argument("Wrong date format: " + error);
        peekCheck(stream);
        stream.ignore(1);
        if(!(stream >> day))
            throw invalid_argument("Wrong date format: " + error);
        if(stream.peek() != ' ' && stream.peek() != EOF)
            throw invalid_argument("Wrong date format: " + error);
        if(month < 1 || month > 12)
            throw invalid_argument("Month value is invalid: " + to_string(month));
        if(day < 1 || day > 31)
            throw invalid_argument("Day value is invalid: " + to_string(day));
        date = {year, month, day};
    } catch(exception& ex){
        cout << ex.what() << endl;
        exit(0);
    }
    return stream;
}

ostream& operator<<(ostream& stream, const Date& date){
    stream << setw(4) << setfill('0') << date.GetYear() << '-' << setw(2) << setfill('0') << date.GetMonth() << '-' << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

class Database {
public:
	void AddEvent(const Date& date, const string& event){
        db[date].insert(event);
    }
	bool DeleteEvent(const Date& date, const string& event){
        if(db[date].find(event) == db[date].end())
            return 0;
        db[date].erase(event);
        if(db[date].size() == 0)
            db.erase(date);
        return 1;
    }

	int DeleteDate(const Date& date){
        if(db.find(date) == db.end())
            return 0;
        int i = db[date].size();
        db.erase(date);
        return i;
    }

	void Find(const Date& date) const{
        if(db.find(date) == db.end())
            exit(0);
        for(const auto& c : db.at(date))
            cout << c << endl;
    }
	
    bool IsFound(const string& key, const Date& date){
        if(db[date].find(key) != end(db[date]))
            return 1;
        return 0;
    }    

	void Print() const{
        for(const auto& c : db){
            for(const auto& w : c.second)
                cout << c.first << ' ' << w << endl;
            cout << endl;
        }
    }
private:
    map<Date, set<string>, less<Date>> db;
};

int main() {
	Database db;
	string command, cmd, ttt;
    string event;
	while (getline(cin, command)) {
        if(command.size() == 0)
            continue;
        Date date;
        //Command cmd(command);
        stringstream command_stream(command);
        stringstream temp(command);
        command_stream >> cmd;
        temp >> ttt >> error;

		if(cmd == "Add"){
                command_stream >> date;            
                command_stream >> event;
            if(db.IsFound(event, date))
                continue;
            //cout << endl << event << endl;
            db.AddEvent(date, event);
            continue;
        }

        else if(cmd == "Del"){
            command_stream >> date;
            if(command_stream.peek() == EOF){
                int i = db.DeleteDate(date);
                cout << "Deleted " << i << " events" << endl;
                //cout << date << endl;
            }
            else{
                command_stream >> event;
                if(!db.DeleteEvent(date, event))
                    cout << "Event not found" << endl;
                else 
                    cout << "Deleted successfully" << endl;
            }
            //cout << "Deleted successfully" << endl;
            continue;
        }

        else if(cmd == "Find"){
            command_stream >> date;
            db.Find(date);
            continue;
        }

        else if(cmd == "Print"){
            db.Print();
            continue;
        }
        cout << "Unknown command: " << command << endl;
	}
    system("pause");
    return 0;
}