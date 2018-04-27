#include <iostream>
using namespace std;

int main() {

    int num = 10;
    int a[] = {1, 2, 3, 4, 5};
    const unsigned N = sizeof(a) / sizeof(a[0]);

    for(int i=0;i<N;i++)
        cout << "a[" << i << "]=" << a[i] << endl;

    auto f = [&] () {
            for (auto k=0U; k<N; ++k) {
                a[k] += num;
            }
        };

    f();

    for(int i=0;i<N;i++)
        cout << "a[" << i << "]=" << a[i] << endl;

    return 0;
}