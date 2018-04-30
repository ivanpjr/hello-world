#include <iostream>
#include <iomanip>

using namespace std;

class Currency{
    string _name;
    double _rate;
public:
    double rate() const {return _rate;}
    string name() const {return _name;}
};

class Money {
    double value;
    const Currency& cur;
public:
    Money(double val, const Currency& cur):value{val}, cur{cur} {}
    double amount() const {return value;}
    const Currency& currency() const {return cur;}

    Money convert(const Currency& to) const {
        return {value * to.rate() / cur.rate(), to};
    }

    friend ostream& operator <<(ostream& os, const Money& m){
        return os << m.currency().name() << " " << fixed << setprecision(2) << m.amount();
    }
};

int main() {

    return 0;
}