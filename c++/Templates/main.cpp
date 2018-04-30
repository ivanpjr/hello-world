#include <iostream>
using namespace std;

template<typename T1, typename T2, typename T3>
bool equals(T1 t1, T2 t2, T3 t3) {cout << __PRETTY_FUNCTION__; return (t1==t2) && (t2==t3);}

int main() {

    cout << boolalpha << equals(1, 2, 3) << endl;
    cout << boolalpha << equals(1, 1, 1U) << endl;
    cout << boolalpha << equals(1, 1, 1L) << endl;
    cout << boolalpha << equals(1, 2, 3.0) << endl;
    cout << boolalpha << equals(1, 2, 'a') << endl;
    cout << boolalpha << equals("a", "a", "a") << endl;
    cout << boolalpha << equals("a", "b", "a") << endl;

    return 0;
}

