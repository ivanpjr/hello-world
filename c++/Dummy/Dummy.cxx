#include <iostream>
#include <stdexcept>
using namespace std;

class Dummy {
    unsigned value;
public:
    static unsigned count;
    Dummy() {++count; cout << toString();}
    Dummy(unsigned v) : value{v} {++count; cout << toString();}
    ~Dummy() {--count;}
    unsigned int getValue() const {return value;}
    void setValue(unsigned int v) {Dummy::value = v;}
    string toString() {return "Dummy{" + to_string(value) + "}\n";}
};
unsigned Dummy::count = 0;

void f(int n) {

    Dummy d;

    if (n<=1) {
        throw domain_error("some error in 1");
    }
    if (n==5) {
        throw domain_error("some error in 5");
    }

    f(n-1);
}


int main() {
    try {
        f(3);
    } catch (logic_error& err) {
        cout << "*** " << err.what() << endl;
    }

    cout << "-------------------" << endl;
    try {
        f(8);
    } catch (logic_error& err) {
        cout << "*** " << err.what() << endl;
    }

    cout << "-------------------" << endl;
//    f(10); //program will be terminated (error), as no one is catching the exception thrown

    return 0;
}