#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <set>
#include <map>
using namespace std;

bool isLow(int a, int b){
    if(a < 0)
        if(b < 0)
            return 0;
        else
            return 1;
    else 
        if(b < 0)
            return 1;
    return 0;
}

int gcd(int a, int b){
    if(a == 0)
        return 1;
    while(a > 0 && b > 0){
        if(a > b)
            a = a % b;
        else 
            b = b % a;
    }
    return a + b;
}

class Rational {
private:
    int numerator, denominator;
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator, int denominator) {
        int g = gcd(abs(numerator), abs(denominator));
        this->numerator = (int)(isLow(numerator, denominator)) ? (-abs(numerator) / g) : (abs(numerator) / g);
        this->denominator = (numerator == 0) ? 1 : (abs(denominator) / g);
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }
};

bool operator==(const Rational& a, const Rational& b){
    return (a.Denominator() == b.Denominator()) && (a.Numerator() == b.Numerator());
}

Rational operator+(const Rational& a, const Rational& b){
    /*int g1 = gcd(abs(a.Denominator()), abs(b.Denominator()));
    int d1 = a.Denominator() / g1, d2 = b.Denominator() / g1;
    return {a.Numerator() * d2 + d1 * b.Numerator(), d1 * d2 * g1};*/
    return Rational {a.Numerator() * b.Denominator() + a.Denominator() * b.Numerator(), a.Denominator() * b.Denominator()};
}

Rational operator-(const Rational& a){
    return Rational(-a.Numerator(), a.Denominator());
}

Rational operator-(const Rational& a, const Rational& b){
    return a + (-b);
}

Rational operator*(const Rational& a, const Rational& b){
    int g1 = gcd(b.Numerator(), a.Denominator());
    int g2 = gcd(a.Numerator(), b.Denominator());
    return Rational((a.Numerator() / g2) * (b.Numerator() / g1), (a.Denominator() / g1) * (b.Denominator() / g2));
}

Rational operator/(const Rational& a, const Rational& b){
    return a * Rational(b.Denominator(), b.Numerator());
}

istream& operator>>(istream& stream, Rational& a){
    int numerator = a.Numerator(), denominator = a.Denominator();
    stream >> numerator;
    stream.ignore(1);
    stream >> denominator;
    //stream.ignore(1);
    a = Rational(numerator, denominator);
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& a){
    stream << a.Numerator() << '/'<< a.Denominator();
    return stream;
}

bool operator<(const Rational& a, const Rational& b){
    return ((double)(a.Numerator() / a.Denominator())) < ((double)(b.Numerator() / b.Denominator()));
}
bool operator>(const Rational& a, const Rational& b){
    return !(a < b);
}

int main() {

    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            cout << rs.size();
            //system("pause");
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }
/*
    set<Rational> s = {{3, 5}};
    s.insert({1, 7});
    Rational f = {4, 5};
    cout <<  " " << s.size() << ' ';
    for(const auto& c : s)
        cout << c;
    Rational a = {1, 2};
    Rational b = {1, 25};
    cout << (a < b) << ' ' << (a > b);*/
    system("pause");
    cout << "OK" << endl;
    return 0;
}
